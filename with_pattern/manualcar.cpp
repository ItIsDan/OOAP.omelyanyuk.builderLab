#include "manualcar.h"

ManualCar::ManualCar()
{
    setName("Manual Car");
}

QString ManualCar::driveMode()
{
    return _driveMode;
}

void ManualCar::setDriveMode(const QString &driveMode)
{
    if (_driveMode == driveMode)
        return;

    _driveMode = driveMode;
}

QStringList ManualCar::showParameters()
{
    return {
        "Name:", "Exterior:", "Interior:", "Comfort:", "Safety:", "Multimedia:", "Drive Mode:"
    };
}

QStringList ManualCar::showAll()
{
    return { name(), exterior(), interior(), comfort(), safety(), multimedia(), driveMode() };
}
