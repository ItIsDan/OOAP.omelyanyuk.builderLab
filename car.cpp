#include "car.h"
#include "QDebug"

Car::Car()
{}

Car::Car(const QString &exterior,
         const QString &interior,
         const QString &comfort,
         const QString &safety,
         const QString &multimedia)
{
    if (exterior == "" || interior == "" || comfort == "" || safety == "" || multimedia == "")
        throw nullptr;

    _exterior = exterior;
    _interior = interior;
    _comfort = comfort;
    _safety = safety;
    _multimedia = multimedia;
}

QString Car::name()
{
    return _name;
}

void Car::setName(const QString &name)
{
    if (_name == name)
        return;

    _name = name;
}

QString Car::exterior()
{
    return _exterior;
}

void Car::setExterior(const QString &exterior)
{
    if (_exterior == exterior)
        return;

    _exterior = exterior;
}

QString Car::interior()
{
    return _interior;
}

void Car::setInterior(const QString &interior)
{
    if (_interior == interior)
        return;

    _interior = interior;
}

QString Car::comfort()
{
    return _comfort;
}

void Car::setComfort(const QString &comfort)
{
    if (_comfort == comfort)
        return;

    _comfort = comfort;
}

QString Car::safety()
{
    return _safety;
}

void Car::setSafety(const QString &safety)
{
    if (_safety == safety)
        return;

    _safety = safety;
}

QString Car::multimedia()
{
    return _multimedia;
}

void Car::setMultimedia(const QString &multimedia)
{
    if (_multimedia == multimedia)
        return;

    _multimedia = multimedia;
}
