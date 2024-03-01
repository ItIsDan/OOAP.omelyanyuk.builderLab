#include "mainwindow.h"
#include <QBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400, 600);
    auto centralWidget = new QWidget(this);
    auto layout = new QGridLayout(centralWidget);

    auto labelExterior = new QLabel("Exterior:");
    _comboExterior = new QComboBox();
    _controls.push_back(_comboExterior);

    auto labelInterior = new QLabel("Interior:");
    _comboInterior = new QComboBox();
    _controls.push_back(_comboInterior);

    auto labelComfort = new QLabel("Comfort:");
    _comboComfort = new QComboBox();
    _controls.push_back(_comboComfort);

    auto labelSafety = new QLabel("Safety:");
    _comboSafety = new QComboBox();
    _controls.push_back(_comboSafety);

    auto labelMultimedia = new QLabel("Multimedia:");
    _comboMultimedia = new QComboBox();
    _controls.push_back(_comboMultimedia);

    _buttonBuild = new QPushButton("Build Configuration");

    _listView = new QListWidget();

    setConnections();

    layout->addWidget(labelExterior, 0, 0);
    layout->addWidget(_comboExterior, 0, 1, 1, 1);
    layout->addWidget(labelInterior);
    layout->addWidget(_comboInterior);
    layout->addWidget(labelComfort);
    layout->addWidget(_comboComfort);
    layout->addWidget(labelSafety);
    layout->addWidget(_comboSafety);
    layout->addWidget(labelMultimedia);
    layout->addWidget(_comboMultimedia);
    layout->addWidget(_buttonBuild, 5, 0, 1, 2);
    layout->addWidget(_listView, 7, 0, 2, 2);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::setConnections()
{
    connect(_buttonBuild, &QPushButton::clicked, this, [this] {
        for (const auto &control : qAsConst(_controls)) {
            qInfo() << control->currentText();
        }
    });
}

MainWindow::~MainWindow()
{}
