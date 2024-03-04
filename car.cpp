#include "car.h"

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

    emit nameChanged(name);
}

QString Car::exterior()
{
    return _exterior;
}

QString Car::interior()
{
    return _interior;
}

QString Car::comfort()
{
    return _comfort;
}

QString Car::safety()
{
    return _safety;
}

QString Car::multimedia()
{
    return _multimedia;
}

QStringList Car::showParameters()
{
    return { "Name", "Exterior", "Interior", "Comfort", "Safety", "Multimedia" };
}

QStringList Car::showAll()
{
    return { name(), exterior(), interior(), comfort(), safety(), multimedia() };
}
