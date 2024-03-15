#include "automaticcarbuilder.h"
#include "QDebug"

AutomaticCarBuilder::AutomaticCarBuilder()
{
    reset();
}

void AutomaticCarBuilder::reset()
{
    _automaticCar = new AutomaticCar();
    emit resetted();
}

void AutomaticCarBuilder::setName(const QString &name)
{
    _automaticCar->setName(name);
}

void AutomaticCarBuilder::setExterior(const QString &exterior)
{
    _automaticCar->setExterior(exterior);
}

void AutomaticCarBuilder::setInterior(const QString &interior)
{
    _automaticCar->setInterior(interior);
}

void AutomaticCarBuilder::setComfort(const QString &comfort)
{
    _automaticCar->setComfort(comfort);
}

void AutomaticCarBuilder::setSafety(const QString &safety)
{
    _automaticCar->setSafety(safety);
}

void AutomaticCarBuilder::setMultimedia(const QString &multimedia)
{
    _automaticCar->setMultimedia(multimedia);
}

void AutomaticCarBuilder::setAutoDrive(const QString &autoDrive)
{
    _automaticCar->setAutoDrive(autoDrive);
}

const QString AutomaticCarBuilder::builderName()
{
    return "Automatic Car Builder";
}

AutomaticCar *AutomaticCarBuilder::result()
{
    auto car = _automaticCar;
    reset();
    return car;
}
