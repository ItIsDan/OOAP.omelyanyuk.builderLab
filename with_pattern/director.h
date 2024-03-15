#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
// #include "IBuilder.h"
class Car;
class IBuilder;

class Director : public QObject
{
    Q_OBJECT
public:
    explicit Director(QObject *parent = nullptr);

    void setBuilder(IBuilder *builder);

    Car *makeCar();

private:
    IBuilder *_carBuilder;
};

#endif // DIRECTOR_H
