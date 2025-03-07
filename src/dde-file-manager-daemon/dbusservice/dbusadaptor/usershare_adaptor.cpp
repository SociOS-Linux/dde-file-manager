/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i usershare/usersharemanager.h -c UserShareAdaptor -l UserShareManager -a dbusadaptor/usershare_adaptor usershare.xml
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "dbusadaptor/usershare_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class UserShareAdaptor
 */

UserShareAdaptor::UserShareAdaptor(UserShareManager *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

UserShareAdaptor::~UserShareAdaptor()
{
    // destructor
}

bool UserShareAdaptor::addGroup(const QString &groupName)
{
    // handle method call com.deepin.filemanager.daemon.UserShareManager.addGroup
    return parent()->addGroup(groupName);
}

bool UserShareAdaptor::closeSmbShareByShareName(const QString &sharename, bool bshow)
{
    // handle method call com.deepin.filemanager.daemon.UserShareManager.closeSmbShareByShareName
    return parent()->closeSmbShareByShareName(sharename, bshow);
}

bool UserShareAdaptor::createShareLinkFile()
{
    // handle method call com.deepin.filemanager.daemon.UserShareManager.createShareLinkFile
    return parent()->createShareLinkFile();
}

bool UserShareAdaptor::isUserSharePasswordSet(const QString &username)
{
    // handle method call com.deepin.filemanager.daemon.UserShareManager.isUserSharePasswordSet
    return parent()->isUserSharePasswordSet(username);
}

bool UserShareAdaptor::setUserSharePassword(const QString &username, const QString &passward)
{
    // handle method call com.deepin.filemanager.daemon.UserShareManager.setUserSharePassword
    return parent()->setUserSharePassword(username, passward);
}

