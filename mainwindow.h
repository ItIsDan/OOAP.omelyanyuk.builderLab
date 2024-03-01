#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QPair>
#include <QCheckBox>
#include "car.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setConnections();

    QCheckBox *_outputInfo;
    QComboBox *_comboExterior;
    QComboBox *_comboInterior;
    QComboBox *_comboComfort;
    QComboBox *_comboSafety;
    QComboBox *_comboMultimedia;
    QVector<QPair<QLabel *, QComboBox *> *> _controls;
    QPushButton *_buttonBuild;
    QListWidget *_listView;
    QListWidget *_labInfo;
};
#endif // MAINWINDOW_H
