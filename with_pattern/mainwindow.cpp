#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(300, 476);

    allocateElements();

    modifyElements();

    setConnections();

    arrangeElements();
}

void MainWindow::allocateElements()
{
    centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);

    _director = new Director();
    _manualCarBuilder = new ManualCarBuilder();
    _automaticCarBuilder = new AutomaticCarBuilder();

    _comboChoice = new QComboBox();

    _nameOfCar = new QLineEdit();

    _labelExterior = new QLabel("Exterior:");
    _comboExterior = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelExterior, _comboExterior));

    _labelInterior = new QLabel("Interior:");
    _comboInterior = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelInterior, _comboInterior));

    _labelComfort = new QLabel("Comfort:");
    _comboComfort = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelComfort, _comboComfort));

    _labelSafety = new QLabel("Safety:");
    _comboSafety = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelSafety, _comboSafety));

    _labelMultimedia = new QLabel("Multimedia:");
    _comboMultimedia = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelMultimedia, _comboMultimedia));

    _labelDriveMode = new QLabel("Drive Mode:");
    _comboDriveMode = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelDriveMode, _comboDriveMode));

    _labelAutoDrive = new QLabel("Auto Drive:");
    _comboAutoDrive = new QComboBox();
    _controls.push_back(new QPair<QLabel *, QComboBox *>(_labelAutoDrive, _comboAutoDrive));

    _buttonBuild = new QPushButton("Build Configuration");

    _outputInfo = new QCheckBox("Output Info");

    _listView = new QListWidget();
    _labInfo = new QListWidget();
    _clear = new QPushButton("Clear");
}

void MainWindow::modifyElements()
{
    _nameOfCar->setAlignment(Qt::AlignRight);

    _labInfo->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    _director->setBuilder(_manualCarBuilder);

    _comboChoice->addItems({ "Manual Car", "Automatic Car" });

    _comboExterior->addItems({ "", "1", "2" });

    _comboInterior->addItems({ "", "1", "2" });

    _comboComfort->addItems({ "", "1", "2" });

    _comboSafety->addItems({ "", "1", "2" });

    _comboMultimedia->addItems({ "", "1", "2" });

    _comboDriveMode->addItems({ "", "All wheels", "Front wheels", "Back wheels" });

    _comboAutoDrive->addItems({ "", "Semi-auto", "AI" });
}

void MainWindow::arrangeElements()
{
    //    layout->addWidget(_outputInfo);
    layout->addWidget(_comboChoice, 0, 0);
    layout->addWidget(_nameOfCar, 0, 1);
    layout->addWidget(_labelExterior, 1, 0);
    layout->addWidget(_comboExterior, 1, 1, 1, 1);
    layout->addWidget(_labelInterior);
    layout->addWidget(_comboInterior);
    layout->addWidget(_labelComfort);
    layout->addWidget(_comboComfort);
    layout->addWidget(_labelSafety);
    layout->addWidget(_comboSafety);
    layout->addWidget(_labelMultimedia);
    layout->addWidget(_comboMultimedia);
    layout->addWidget(_labelDriveMode);
    layout->addWidget(_comboDriveMode);
    layout->addWidget(_buttonBuild, 7, 0, 1, 2);
    layout->addWidget(_labInfo, 8, 0, 2, 2);
    layout->addWidget(_clear, 10, 0, 1, 2);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
void MainWindow::setConnections()
{
    connect(_buttonBuild, &QPushButton::clicked, this, [this] {
        //        if (_outputInfo->isChecked()) {
        //            QString buffer;
        //            bool err = false;
        //            for (const auto &control : qAsConst(_controls)) {
        //                buffer.push_back(control->first->text());
        //                buffer.push_back(" ");
        //                buffer.push_back(control->second->currentText());
        //                buffer.push_back("\n");
        //                if (control->second->currentText() == "")
        //                    err = true;
        //            }
        //            if (err)
        //                buffer.append("ERROR: Some part is empty");
        //            _listView->addItem(buffer);
        //            return;
        //        }

        handleNewCar(_director->makeCar());
    });

    connect(_comboChoice, &QComboBox::currentTextChanged, this, [this](auto text) {
        if (text == "Manual Car") {
            _director->setBuilder(_manualCarBuilder);
            _labelDriveMode->setVisible(true);
            _comboDriveMode->setVisible(true);
            layout->replaceWidget(_labelAutoDrive, _labelDriveMode);
            layout->replaceWidget(_comboAutoDrive, _comboDriveMode);
            _labelAutoDrive->setVisible(false);
            _comboAutoDrive->setVisible(false);
        }
        if (text == "Automatic Car") {
            _director->setBuilder(_automaticCarBuilder);
            _labelAutoDrive->setVisible(true);
            _comboAutoDrive->setVisible(true);
            layout->replaceWidget(_labelDriveMode, _labelAutoDrive);
            layout->replaceWidget(_comboDriveMode, _comboAutoDrive);
            _labelDriveMode->setVisible(false);
            _comboDriveMode->setVisible(false);
        }
    });

    connect(_nameOfCar, &QLineEdit::textEdited, this, [this](auto name) {
        if (name.isEmpty()) {
            _manualCarBuilder->setName("Manual Car");
            _automaticCarBuilder->setName("Automatic Car");
            return;
        } else {
            _manualCarBuilder->setName(name);
            _automaticCarBuilder->setName(name);
        }
    });

    connect(comboExterior(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setExterior(text);
        _automaticCarBuilder->setExterior(text);
    });

    connect(comboInterior(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setInterior(text);
        _automaticCarBuilder->setInterior(text);
    });

    connect(comboComfort(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setComfort(text);
        _automaticCarBuilder->setComfort(text);
    });

    connect(comboSafety(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setSafety(text);
        _automaticCarBuilder->setSafety(text);
    });

    connect(comboMultimedia(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setMultimedia(text);
        _automaticCarBuilder->setMultimedia(text);
    });

    connect(comboAutoDrive(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _automaticCarBuilder->setAutoDrive(text);
    });

    connect(comboDriveMode(), &QComboBox::currentTextChanged, this, [this](auto text) {
        _manualCarBuilder->setDriveMode(text);
    });

    connect(_automaticCarBuilder, &AutomaticCarBuilder::resetted, this, [this]() {
        _automaticCarBuilder->setName(_nameOfCar->text().isEmpty() ? "Automatic Car"
                                                                   : _nameOfCar->text());
        _automaticCarBuilder->setExterior(comboExterior()->currentText());
        _automaticCarBuilder->setInterior(comboInterior()->currentText());
        _automaticCarBuilder->setComfort(comboComfort()->currentText());
        _automaticCarBuilder->setSafety(comboSafety()->currentText());
        _automaticCarBuilder->setMultimedia(comboMultimedia()->currentText());
        _automaticCarBuilder->setAutoDrive(comboAutoDrive()->currentText());
    });

    connect(_manualCarBuilder, &ManualCarBuilder::resetted, this, [this]() {
        _manualCarBuilder->setName(_nameOfCar->text().isEmpty() ? "Manual Car"
                                                                : _nameOfCar->text());
        _manualCarBuilder->setExterior(comboExterior()->currentText());
        _manualCarBuilder->setInterior(comboInterior()->currentText());
        _manualCarBuilder->setComfort(comboComfort()->currentText());
        _manualCarBuilder->setSafety(comboSafety()->currentText());
        _manualCarBuilder->setMultimedia(comboMultimedia()->currentText());
        _manualCarBuilder->setDriveMode(comboDriveMode()->currentText());
    });

    connect(_outputInfo, &QCheckBox::clicked, this, [this](auto checked) {
        if (checked) {
            layout->replaceWidget(_labInfo, _listView);
            _labInfo->setVisible(false);
            _listView->setVisible(true);
        } else {
            layout->replaceWidget(_listView, _labInfo);
            _listView->setVisible(false);
            _labInfo->setVisible(true);
        }
    });

    connect(_clear, &QPushButton::clicked, this, [this]() {
        _labInfo->clear();
        _cars.clear();
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

QComboBox *MainWindow::comboExterior()
{
    return _comboExterior;
}

QComboBox *MainWindow::comboInterior()
{
    return _comboInterior;
}

QComboBox *MainWindow::comboComfort()
{
    return _comboComfort;
}

QComboBox *MainWindow::comboSafety()
{
    return _comboSafety;
}

QComboBox *MainWindow::comboMultimedia()
{
    return _comboMultimedia;
}

QComboBox *MainWindow::comboDriveMode()
{
    return _comboDriveMode;
}

QComboBox *MainWindow::comboAutoDrive()
{
    return _comboAutoDrive;
}

void MainWindow::handleNewCar(Car *car)
{
    _cars.append(car);
    QString buffer;
    for (int i = 0; i < car->showParameters().size(); ++i) {
        if (car->showAll()[i] == "")
            continue;
        buffer.push_back(car->showParameters()[i]);
        buffer.push_back(" ");
        buffer.push_back(car->showAll()[i]);
        buffer.push_back("\n");
    }
    buffer.chop(1);
    _labInfo->addItem(buffer);
}
