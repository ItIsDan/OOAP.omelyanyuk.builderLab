#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>

class Car : public QObject
{
    Q_OBJECT
public:
    explicit Car(QObject *parent = nullptr);

    //    explicit Car(QString, QString, QString, QString, QString) = default;
signals:
};

#endif // CAR_H
