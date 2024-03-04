#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>

class Director : public QObject
{
    Q_OBJECT
public:
    explicit Director(QObject *parent = nullptr);

signals:

};

#endif // DIRECTOR_H
