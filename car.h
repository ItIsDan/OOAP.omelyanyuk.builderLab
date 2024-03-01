#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>

class Car : public QObject
{
    Q_OBJECT
public:
    //    explicit Car(QObject *parent = nullptr);

    explicit Car(const QString &exterior,
                 const QString &interior,
                 const QString &comfort,
                 const QString &safety,
                 const QString &multimedia);

    QString exterior();
    QString interior();
    QString comfort();
    QString safety();
    QString multimedia();
    QStringList showParameters();
    QStringList showAll();

signals:

private:
    QString _exterior;
    QString _interior;
    QString _comfort;
    QString _safety;
    QString _multimedia;
};

#endif // CAR_H
