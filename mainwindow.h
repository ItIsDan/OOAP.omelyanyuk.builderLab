#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QPair>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setConnections();

    QComboBox *_comboExterior;
    QComboBox *_comboInterior;
    QComboBox *_comboComfort;
    QComboBox *_comboSafety;
    QComboBox *_comboMultimedia;
    QVector<QPair<QLabel *, QComboBox *> *> _controls;
    QPushButton *_buttonBuild;
    QListWidget *_listView;
};
#endif // MAINWINDOW_H
