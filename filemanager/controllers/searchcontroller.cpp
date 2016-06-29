#include "searchcontroller.h"
#include "fileservices.h"

#include "../models/searchfileinfo.h"
#include "../models/ddiriterator.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrentRun>
#include <QDirIterator>
#include <QRegularExpression>

SearchController::SearchController(QObject *parent)
    : AbstractFileController(parent)
{

}

const QList<AbstractFileInfoPointer> SearchController::getChildren(const DUrl &fileUrl, QDir::Filters filter, bool &accepted) const
{
    accepted = true;

    if(fileUrl.isStopSearch()) {
        activeJob.remove(fileUrl.searchTargetUrl());
    } else {
        activeJob << fileUrl.searchTargetUrl();

        QtConcurrent::run(QThreadPool::globalInstance(), const_cast<SearchController*>(this),
                          &SearchController::searchStart, fileUrl, filter);
    }

    return QList<AbstractFileInfoPointer>();
}

const AbstractFileInfoPointer SearchController::createFileInfo(const DUrl &fileUrl, bool &accepted) const
{
    accepted = true;

    return AbstractFileInfoPointer(new SearchFileInfo(fileUrl));
}

bool SearchController::openFileLocation(const DUrl &fileUrl, bool &accepted) const
{
    accepted = true;

    return FileServices::instance()->openFileLocation(DUrl(fileUrl.fragment()));
}

void SearchController::searchStart(const DUrl &fileUrl, QDir::Filters filter)
{
    const DUrl &targetUrl = fileUrl.searchTargetUrl();
    const QString &keyword = fileUrl.searchKeyword();

    QRegularExpression regular(keyword, QRegularExpression::CaseInsensitiveOption);

    QList<DUrl> searchPathList;

    searchPathList << targetUrl;

    qDebug() << "begin search:" << fileUrl;

    while(!searchPathList.isEmpty()) {
        const DUrl &url = searchPathList.takeAt(0);

        DDirIteratorPointer it = FileServices::instance()->createDirIterator(url, QDir::NoDotAndDotDot | filter,
                                                                             QDirIterator::NoIteratorFlags);

        if (!it) {
            searchPathList.removeOne(url);

            continue;
        }

        while (it->hasNext()) {
            if(!activeJob.contains(targetUrl)) {
                qDebug() << "stop search:" << fileUrl;

                return;
            }

            AbstractFileInfoPointer fileInfo = FileServices::instance()->createFileInfo(it->next());

            fileInfo->makeAbsolute();

            if(fileInfo->isDir()) {
                const DUrl &url = fileInfo->fileUrl();

                if (!searchPathList.contains(url))
                    searchPathList << url;
            }

            if(fileInfo->fileName().indexOf(regular) >= 0) {
                DUrl url = fileUrl;

                url.setFragment(fileInfo->fileUrl().toString());

                emit childrenAdded(url);

                QThread::msleep(50);
            }
        }
    }

    qDebug() << "search finished:" << fileUrl;
}
