#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400, 600);
    auto centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);

    _comboChoice = new QComboBox();
    _comboChoice->addItems({ "Manual Car", "Automatic Car" });

    auto *labelExterior = new QLabel("Exterior:");
    _comboExterior = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelExterior, _comboExterior));
    _comboExterior->addItems({ "", "1", "2" });

    auto labelInterior = new QLabel("Interior:");
    _comboInterior = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelInterior, _comboInterior));
    _comboInterior->addItems({ "", "1", "2" });

    auto labelComfort = new QLabel("Comfort:");
    _comboComfort = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelComfort, _comboComfort));
    _comboComfort->addItems({ "", "1", "2" });

    auto labelSafety = new QLabel("Safety:");
    _comboSafety = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelSafety, _comboSafety));
    _comboSafety->addItems({ "", "1", "2" });

    auto labelMultimedia = new QLabel("Multimedia:");
    _comboMultimedia = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelMultimedia, _comboMultimedia));
    _comboMultimedia->addItems({ "", "1", "2" });

    auto labelDriveMode = new QLabel("Drive Mode:");
    _comboDriveMode = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelDriveMode, _comboDriveMode));
    _comboDriveMode->addItems({ "", "All wheel", "Front wheel", "Roar wheel" });

    auto labelAutoDrive = new QLabel("Auto Drive:");
    _comboAutoDrive = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(labelAutoDrive, _comboAutoDrive));
    _comboAutoDrive->addItems({ "", "None", "AI" });

    _buttonBuild = new QPushButton("Build Configuration");

    _outputInfo = new QCheckBox("Output Info");

    _listView = new QListWidget();
    _labInfo = new QListWidget();

    setConnections();
    layout->addWidget(_outputInfo);
    layout->addWidget(_comboChoice, 0, 1);
    layout->addWidget(labelExterior, 1, 0);
    layout->addWidget(_comboExterior, 1, 1, 1, 1);
    layout->addWidget(labelInterior);
    layout->addWidget(_comboInterior);
    layout->addWidget(labelComfort);
    layout->addWidget(_comboComfort);
    layout->addWidget(labelSafety);
    layout->addWidget(_comboSafety);
    layout->addWidget(labelMultimedia);
    layout->addWidget(_comboMultimedia);
    layout->addWidget(labelDriveMode);
    layout->addWidget(_comboDriveMode);
    layout->addWidget(_buttonBuild, 7, 0, 1, 2);
    layout->addWidget(_listView, 8, 0, 2, 2);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::setConnections()
{
    connect(_buttonBuild, &QPushButton::clicked, this, [this] {
        if (_outputInfo->isChecked()) {
            QString buffer;
            bool err = false;
            for (const auto &control : qAsConst(_controls)) {
                buffer.push_back(control->first->text());
                buffer.push_back(" ");
                buffer.push_back(control->second->currentText());
                buffer.push_back("\n");
                if (control->second->currentText() == "")
                    err = true;
            }
            if (err)
                buffer.append("ERROR: Some part is empty");
            _listView->addItem(buffer);
            return;
        }
        try {
            if (_comboChoice->currentText() == "Manual Car")
                handleNewCar(new Car(_comboExterior->currentText(), _comboInterior->currentText(),
                                     _comboComfort->currentText(), _comboSafety->currentText(),
                                     _comboMultimedia->currentText()));
        } catch (...) {
            qDebug() << "Argument must not be empty";
            move(x() + 10, y());
            _sleep(10);
            move(x() - 20, y());
            _sleep(10);
            move(x() + 10, y());
        }
    });

    connect(_outputInfo, &QCheckBox::clicked, this, [this](auto checked) {
        if (checked)
            layout->replaceWidget(_labInfo, _listView);
        else
            layout->replaceWidget(_listView, _labInfo);
    });

    connect(_labInfo, &QListWidget::currentRowChanged, this, [this](auto currentRow) {
        auto currentCar = _cars[currentRow];
        for (int i = 0; i < _controls.size(); i++)
            _controls[i]->second->setCurrentText(_cars[currentRow]->showAll()[i]);
    });
}

MainWindow::~MainWindow()
{
    delete _outputInfo;
    delete _buttonBuild;
    delete _listView;
    for (const auto &control : qAsConst(_controls)) {
        delete control->first;
        delete control->second;
        delete control;
    }
}

void MainWindow::handleNewCar(Car *car)
{
    _cars.append(car);
    QString buffer;
    for (int i = 0; i < car->showParameters().size(); ++i) {
        buffer.push_back(car->showParameters()[i]);
        buffer.push_back(" ");
        buffer.push_back(car->showAll()[i]);
        buffer.push_back("\n");
    }
    buffer.chop(1);
    _labInfo->addItem(buffer);
}
