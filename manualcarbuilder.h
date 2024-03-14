#ifndef MANUALCARBUILDER_H
#define MANUALCARBUILDER_H

#include <QObject>
#include "IBuilder.h"
#include "manualcar.h"

class ManualCarBuilder : public IBuilder
{
    Q_OBJECT
public:
    explicit ManualCarBuilder();

    void reset();
    void setName(const QString &name) override;
    void setExterior(const QString &exterior) override;
    void setInterior(const QString &interior) override;
    void setComfort(const QString &comfort) override;
    void setSafety(const QString &safety) override;
    void setMultimedia(const QString &multimedia) override;
    void setDriveMode(const QString &driveMode);
    const QString builderName() override;
    ManualCar *result();

private:
    ManualCar *_manualCar { nullptr };
signals:
    void resetted();
};

#endif // MANUALCARBUILDER_H
