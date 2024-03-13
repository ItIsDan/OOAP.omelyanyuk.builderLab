#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QPair>
#include <QCheckBox>
#include <QBoxLayout>
// #include "car.h"
#include "manualcar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setConnections();
    void handleNewCar(Car *car);

    QGridLayout *layout;

    QCheckBox *_outputInfo;
    QComboBox *_comboChoice;
    QComboBox *_comboExterior;
    QComboBox *_comboInterior;
    QComboBox *_comboComfort;
    QComboBox *_comboSafety;
    QComboBox *_comboMultimedia;
    QComboBox *_comboDriveMode;
    QComboBox *_comboAutoDrive;
    QVector<QPair<QLabel *, QComboBox *> *> _controls;
    QPushButton *_buttonBuild;
    QListWidget *_listView;
    QListWidget *_labInfo;
    QVector<Car *> _cars;
};
#endif // MAINWINDOW_H
