#ifndef MANUALCAR_H
#define MANUALCAR_H

#include "car.h"
#include <QObject>

class ManualCar : public Car
{
    Q_OBJECT
public:
    explicit ManualCar();

signals:
};

#endif // MANUALCAR_H
