#ifndef MANUALCAR_H
#define MANUALCAR_H

#include "car.h"
#include <QObject>

class ManualCar : public Car
{
    Q_OBJECT
public:
    explicit ManualCar();

    QString driveMode();
    void setDriveMode(const QString &driveMode);

    QStringList showParameters();
    QStringList showAll();

private:
    QString _driveMode;
};

#endif // MANUALCAR_H
