#ifndef AUTOMATICCARBUILDER_H
#define AUTOMATICCARBUILDER_H

#include <QObject>
#include "IBuilder.h"
#include "automaticcar.h"

class AutomaticCarBuilder : public IBuilder
{
    Q_OBJECT
public:
    explicit AutomaticCarBuilder();

    void reset() override;
    void setName(const QString &name) override;
    void setExterior(const QString &exterior) override;
    void setInterior(const QString &interior) override;
    void setComfort(const QString &comfort) override;
    void setSafety(const QString &safety) override;
    void setMultimedia(const QString &multimedia) override;
    void setAutoDrive(const QString &autoDrive);

    const QString builderName() override;
    AutomaticCar *result() override;

private:
    AutomaticCar *_automaticCar { nullptr };

signals:
    void resetted();
};

#endif // AUTOMATICCARBUILDER_H
