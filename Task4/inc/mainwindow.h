#pragma once
#include <QMainWindow>
#include <QWidget>
#include <memory>

#include "Lift.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() = default;

private:
    QWidget *widget;    
    Lift _lift;
};