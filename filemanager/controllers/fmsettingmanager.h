#ifndef FMSETTINGMANAGER_H
#define FMSETTINGMANAGER_H

#include "basemanager.h"

#include <QObject>

class FMSettingManager : public QObject, public BaseManager
{
    Q_OBJECT
public:
    explicit FMSettingManager(QObject *parent = 0);
    ~FMSettingManager();

signals:

public slots:
};

#endif // FMSETTINGMANAGER_H
