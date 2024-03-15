#include "automaticcar.h"

AutomaticCar::AutomaticCar()
{
    setName("Automatic Car");
}

QString AutomaticCar::autoDrive()
{
    return _autoDrive;
}

void AutomaticCar::setAutoDrive(const QString &autoDrive)
{
    if (_autoDrive == autoDrive)
        return;

    _autoDrive = autoDrive;
}

QStringList AutomaticCar::showParameters()
{
    return {
        "Name:", "Exterior:", "Interior:", "Comfort:", "Safety:", "Multimedia:", "Auto Drive:"
    };
}

QStringList AutomaticCar::showAll()
{
    return { name(), exterior(), interior(), comfort(), safety(), multimedia(), autoDrive() };
}
