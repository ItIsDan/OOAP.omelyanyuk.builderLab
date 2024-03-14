#ifndef IBUILDER_H
#define IBUILDER_H

#include "car.h"
#include <QObject>

class IBuilder : public QObject
{
    Q_OBJECT
public:
    virtual void setName(const QString &) = 0;
    virtual void setExterior(const QString &) = 0;
    virtual void setInterior(const QString &) = 0;
    virtual void setComfort(const QString &) = 0;
    virtual void setSafety(const QString &) = 0;
    virtual void setMultimedia(const QString &) = 0;
    virtual Car *result() = 0;
    virtual const QString builderName() = 0;
};

#endif // IBUILDER_H
