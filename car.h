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

    //    // Builder need to react on comboBoxesValueChanges -> builder->car()->setExterior(value);
    //    && add doneCar() on btnClick; void set (const void set (const void set (const void set
    //    (const
    QString name();
    void setName(const QString &name);
    Q_SIGNAL void nameChanged(const QString &name);

    QString exterior();
    QString interior();
    QString comfort();
    QString safety();
    QString multimedia();
    QStringList showParameters();
    QStringList showAll();

signals:

private:
    QString _name { "Car" };
    QString _exterior {};
    QString _interior {};
    QString _comfort {};
    QString _safety {};
    QString _multimedia {};
};

#endif // CAR_H
