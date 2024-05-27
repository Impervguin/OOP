#include "mainwindow.hpp"

#include <QPushButton>
#include <QMessageBox>
#include <cmath>

#include "MatrixLoadCommand.h"
#include "ListLoadCommand.h"
#include "SqliteLoadCommandDecorator.h"
#include "TxtLoadCommandDecorator.h"
#include "DrawSceneQtCommand.h"
#include "GetCameraIDsSceneCommand.h"
#include "GetObjectIDsSceneCommand.h"
#include "AddCameraCommand.h"
#include "SetCameraCommand.h"
#include "RemoveCameraCommand.h"
#include "MoveCameraCommand.h"
#include "ShiftObjectCommand.h"
#include "RotateObjectCommand.h"
#include "ScaleObjectCommand.h"
#include "CompositeObjectCommand.h"
#include "RemoveObjectCommand.h"
#include "Point.h"
#include "baseexception.h"

double DegToRad(double angle) { return angle / 180.0 * M_PI; }


MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene);
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());
    connectButtons();
}

MyMainWindow::~MyMainWindow() {
    delete ui;
}

void MyMainWindow::connectButtons() {
    connect(ui->loadPushButton, &QPushButton::clicked, this, &MyMainWindow::on_loadButton_clicked);
    connect(ui->cameraAddPushbutton, &QPushButton::clicked, this, &MyMainWindow::on_cameraAddPushbutton_clicked);
    connect(ui->cameraDeletePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_cameraDeletePushbutton_clicked);
    connect(ui->cameraSetPushbutton, &QPushButton::clicked, this, &MyMainWindow::on_cameraSetPushbutton_clicked);
    connect(ui->cameraMoveButton, &QPushButton::clicked, this, &MyMainWindow::on_cameraMoveButton_clicked);
    connect(ui->objectMovePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_objectMovePushbutton_clicked);
    connect(ui->objectRotatePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_objectRotatePushbutton_clicked);
    connect(ui->objectScalePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_objectScalePushbutton_clicked);
    connect(ui->objectDeletePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_objectDeletePushbutton_clicked);
    connect(ui->objectCompositePushbutton, &QPushButton::clicked, this, &MyMainWindow::on_objectCompositePushbutton_clicked);
}

void MyMainWindow::on_loadButton_clicked() {
    std::string str = ui->fileLineEdit->text().toStdString();
    const char* fname = str.c_str();
    
    std::shared_ptr<BaseLoadCommand> command;

    if (ui->listRadioButton->isChecked())
        command = std::make_shared<ListLoadCommand>();
    else
        command = std::make_shared<MatrixLoadCommand>();
    
    std::shared_ptr<BaseCommand> decorator;
    if (ui->sqliteRadioButton->isChecked())
        decorator = std::make_shared<SqliteLoadCommandDecorator>(*command, fname);
    else
        decorator = std::make_shared<TxtLoadCommandDecorator>(*command, fname);
    try {
        _facade.Execute(*decorator);
    } catch (BaseException &exc) {
        QMessageBox::critical(nullptr, "Ошибка", exc.what());
        return;
    }
    
    drawScene();
    updateObjectList();
}

void MyMainWindow::on_cameraAddPushbutton_clicked() {
    double x = ui->cameraXSpin->value();
    double y = ui->cameraYSpin->value();
    double z = ui->cameraZSpin->value();
    Point pos(x, y, z);
    AddCameraCommand command(pos);
    _facade.Execute(command);
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_cameraDeletePushbutton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы одну камеру.");
        return;
    }
    for (size_t id : cams) {
        RemoveCameraCommand command(id);
        _facade.Execute(command);
    }
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_cameraSetPushbutton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать ровно одну камеру.");
        return;
    }   
    SetCameraCommand command(cams[0]);
    _facade.Execute(command);
    drawScene();
}

void MyMainWindow::on_cameraMoveButton_clicked() {
    double x = ui->cameraXSpin->value();
    double y = ui->cameraYSpin->value();
    double z = ui->cameraZSpin->value();

    auto cams = getSelectedCameraIds();
    if (cams.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы одну камеру.");
        return;
    }
    for (size_t id : cams) {
        MoveCameraCommand command(id, x, y, z);
        _facade.Execute(command);
    }
    drawScene();
}

void MyMainWindow::updateCameraList() {
    ui->cameraListWidget->clear();
    GetCameraIDsSceneCommand ids;
    _facade.Execute(ids);
    std::vector<size_t> cameraIds = ids.GetIDs();
    for (size_t id : cameraIds) {
        ui->cameraListWidget->addItem(QString::number(id));
    }
}
void MyMainWindow::updateObjectList() {
    ui->objectListWidget->clear();
    GetObjectIDsSceneCommand ids;
    _facade.Execute(ids);
    std::vector<size_t> objectIds = ids.GetIDs();
    for (size_t id : objectIds) {
        ui->objectListWidget->addItem(QString::number(id));
    }
}
std::vector<size_t> MyMainWindow::getSelectedObjectIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->objectListWidget->count(); i++) {
        if (ui->objectListWidget->item(i)->isSelected()) {
            ids.push_back(ui->objectListWidget->item(i)->text().toInt());
        }
    }
    return ids;
}
std::vector<size_t> MyMainWindow::getSelectedCameraIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->cameraListWidget->count(); i++) {
        if (ui->cameraListWidget->item(i)->isSelected()) {
            ids.push_back(ui->cameraListWidget->item(i)->text().toInt());
        }
    }
    return ids;
}

void MyMainWindow::drawScene() {
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());
    DrawSceneQtCommand drawcommand(ui->graphicsView->scene());
    _facade.Execute(drawcommand);
}

void MyMainWindow::on_objectMovePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->obkectMoveXSpin->value();
    double y = ui->objectMoveYSpin->value();
    double z = ui->objectMoveZSpin->value();
    for (auto &id : objs) {
        ShiftObjectCommand command(id, x, y, z);
        _facade.Execute(command);
    }

    drawScene();
}

void MyMainWindow::on_objectRotatePushbutton_clicked() { 
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = DegToRad(ui->objectRotateXSpin->value());
    double y = DegToRad(ui->objectRotateYSpin->value());
    double z = DegToRad(ui->objectRotateZSpin->value());
    for (auto &id : objs) {
        RotateObjectCommand command(id, x, y, z);
        _facade.Execute(command);
    }

    drawScene();
}


void MyMainWindow::on_objectScalePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->objectScaleXSpin->value();
    double y = ui->objectScaleYSpin->value();
    double z = ui->objectScaleZSpin->value();
    for (auto &id : objs) {
        ScaleObjectCommand command(id, x, y, z);
        _facade.Execute(command);
    }

    drawScene();
}

void MyMainWindow::on_objectDeletePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    for (auto &id : objs) {
        RemoveObjectCommand command(id);
        _facade.Execute(command);
    }

    drawScene();
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_objectCompositePushbutton_clicked() { 
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    CompositeObjectCommand command(objs);
    _facade.Execute(command);

    drawScene();
    updateCameraList();
    updateObjectList();
}