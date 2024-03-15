#include "director.h"
#include "mainwindow.h"

Director::Director(QObject *parent) : QObject { parent }
{}

void Director::setBuilder(IBuilder *builder)
{
    _carBuilder = builder;
}

Car *Director::makeCar()
{
    return _carBuilder->result();
}
