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

#include "director.h"
#include "manualcarbuilder.h"
#include "automaticcarbuilder.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QComboBox *comboExterior();
    QComboBox *comboInterior();
    QComboBox *comboComfort();
    QComboBox *comboSafety();
    QComboBox *comboMultimedia();
    QComboBox *comboDriveMode();
    QComboBox *comboAutoDrive();

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

    QLabel *_labelDriveMode;
    QComboBox *_comboDriveMode;
    QLabel *_labelAutoDrive;
    QComboBox *_comboAutoDrive;
    QPushButton *_clear;

    QVector<QPair<QLabel *, QComboBox *> *> _controls;
    QPushButton *_buttonBuild;
    QListWidget *_listView;
    QListWidget *_labInfo;
    QVector<Car *> _cars;

    Director *_director;
    ManualCarBuilder *_manualCarBuilder;
    AutomaticCarBuilder *_automaticCarBuilder;
    void allocateElements();
};
#endif // MAINWINDOW_H
