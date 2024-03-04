#ifndef MANUALCARBUILDER_H
#define MANUALCARBUILDER_H

#include <QObject>

class ManualCarBuilder : public QObject
{
    Q_OBJECT
public:
    explicit ManualCarBuilder(QObject *parent = nullptr);

signals:

};

#endif // MANUALCARBUILDER_H
