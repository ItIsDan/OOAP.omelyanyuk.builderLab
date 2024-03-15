#ifndef AUTOMATICCAR_H
#define AUTOMATICCAR_H

#include "car.h"
#include <QObject>

class AutomaticCar : public Car
{
    Q_OBJECT
public:
    explicit AutomaticCar();

    QString autoDrive();
    void setAutoDrive(const QString &autoDrive);

    QStringList showParameters();
    QStringList showAll();

private:
    QString _autoDrive;
};

#endif // AUTOMATICCAR_H
