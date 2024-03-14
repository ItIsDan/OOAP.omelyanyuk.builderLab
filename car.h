#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>

class Car : public QObject
{
    Q_OBJECT
public:
    explicit Car();

    explicit Car(const QString &exterior,
                 const QString &interior,
                 const QString &comfort,
                 const QString &safety,
                 const QString &multimedia);

    QString name();
    void setName(const QString &name);

    QString exterior();
    void setExterior(const QString &exterior);

    QString interior();
    void setInterior(const QString &interior);

    QString comfort();
    void setComfort(const QString &comfort);

    QString safety();
    void setSafety(const QString &safety);

    QString multimedia();
    void setMultimedia(const QString &multimedia);

    virtual QStringList showParameters() = 0;
    virtual QStringList showAll() = 0;

protected:
    QString _name { "" };
    QString _exterior { "" };
    QString _interior { "" };
    QString _comfort { "" };
    QString _safety { "" };
    QString _multimedia { "" };
};

#endif // CAR_H
