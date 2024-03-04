#ifndef AUTOMATICCAR_H
#define AUTOMATICCAR_H

#include "car.h"
#include <QObject>

class AutomaticCar : public Car
{
    Q_OBJECT
public:
    explicit AutomaticCar();

signals:
};

#endif // AUTOMATICCAR_H
