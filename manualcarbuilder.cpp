#include "manualcarbuilder.h"
#include "QDebug"

ManualCarBuilder::ManualCarBuilder()
{
    reset();
}

void ManualCarBuilder::reset()
{
    _manualCar = new ManualCar();

    emit resetted();
}

void ManualCarBuilder::setName(const QString &name)
{
    _manualCar->setName(name);
}

void ManualCarBuilder::setExterior(const QString &exterior)
{
    _manualCar->setExterior(exterior);
}

void ManualCarBuilder::setInterior(const QString &interior)
{
    _manualCar->setInterior(interior);
}

void ManualCarBuilder::setComfort(const QString &comfort)
{
    _manualCar->setComfort(comfort);
}

void ManualCarBuilder::setSafety(const QString &safety)
{
    _manualCar->setSafety(safety);
}

void ManualCarBuilder::setMultimedia(const QString &multimedia)
{
    _manualCar->setMultimedia(multimedia);
}

void ManualCarBuilder::setDriveMode(const QString &driveMode)
{
    _manualCar->setDriveMode(driveMode);
}

const QString ManualCarBuilder::builderName()
{
    return "Manual Car Builder";
}

ManualCar *ManualCarBuilder::result()
{
    auto car = _manualCar;
    reset();
    return car;
}
