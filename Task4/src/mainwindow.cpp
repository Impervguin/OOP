#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(300, 700);
    this->setWindowTitle("Elevator control panel");
    widget = _lift.GetWidget();
    widget->setGeometry(0, 0, 300, 700);
    widget->setParent(this);
}