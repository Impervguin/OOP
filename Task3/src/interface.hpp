/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGroupBox *loadGroupBox;
    QGroupBox *typeGroupBOx;
    QRadioButton *listRadioButton;
    QRadioButton *matrixRadioButton;
    QLineEdit *fileLineEdit;
    QLabel *label;
    QPushButton *loadPushButton;
    QGroupBox *fileGroupBox;
    QRadioButton *sqliteRadioButton;
    QRadioButton *txtRadioButton;
    QGroupBox *cameraGroupBox;
    QDoubleSpinBox *cameraXSpin;
    QDoubleSpinBox *cameraZSpin;
    QDoubleSpinBox *cameraYSpin;
    QPushButton *cameraAddPushbutton;
    QListWidget *cameraListWidget;
    QPushButton *cameraSetPushbutton;
    QPushButton *cameraDeletePushbutton;
    QPushButton *cameraMoveButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *objectGroupBox;
    QListWidget *objectListWidget;
    QDoubleSpinBox *obkectMoveXSpin;
    QDoubleSpinBox *objectScaleXSpin;
    QDoubleSpinBox *objectRotateXSpin;
    QDoubleSpinBox *objectMoveYSpin;
    QDoubleSpinBox *objectRotateYSpin;
    QDoubleSpinBox *objectScaleYSpin;
    QDoubleSpinBox *objectMoveZSpin;
    QDoubleSpinBox *objectRotateZSpin;
    QDoubleSpinBox *objectScaleZSpin;
    QPushButton *objectDeletePushbutton;
    QPushButton *objectCompositePushbutton;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *objectMovePushbutton;
    QPushButton *objectRotatePushbutton;
    QPushButton *objectScalePushbutton;
    QGroupBox *logGroupBox;
    QTextEdit *logTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1499, 1200);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 900, 900));
        loadGroupBox = new QGroupBox(centralwidget);
        loadGroupBox->setObjectName(QString::fromUtf8("loadGroupBox"));
        loadGroupBox->setGeometry(QRect(910, 0, 581, 201));
        typeGroupBOx = new QGroupBox(loadGroupBox);
        typeGroupBOx->setObjectName(QString::fromUtf8("typeGroupBOx"));
        typeGroupBOx->setGeometry(QRect(9, 89, 241, 71));
        listRadioButton = new QRadioButton(typeGroupBOx);
        listRadioButton->setObjectName(QString::fromUtf8("listRadioButton"));
        listRadioButton->setGeometry(QRect(10, 30, 81, 25));
        listRadioButton->setChecked(true);
        matrixRadioButton = new QRadioButton(typeGroupBOx);
        matrixRadioButton->setObjectName(QString::fromUtf8("matrixRadioButton"));
        matrixRadioButton->setGeometry(QRect(150, 30, 81, 25));
        fileLineEdit = new QLineEdit(loadGroupBox);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
        fileLineEdit->setGeometry(QRect(10, 50, 561, 27));
        label = new QLabel(loadGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 321, 19));
        loadPushButton = new QPushButton(loadGroupBox);
        loadPushButton->setObjectName(QString::fromUtf8("loadPushButton"));
        loadPushButton->setGeometry(QRect(230, 170, 131, 27));
        fileGroupBox = new QGroupBox(loadGroupBox);
        fileGroupBox->setObjectName(QString::fromUtf8("fileGroupBox"));
        fileGroupBox->setGeometry(QRect(330, 90, 241, 71));
        sqliteRadioButton = new QRadioButton(fileGroupBox);
        sqliteRadioButton->setObjectName(QString::fromUtf8("sqliteRadioButton"));
        sqliteRadioButton->setGeometry(QRect(10, 30, 81, 25));
        sqliteRadioButton->setChecked(false);
        txtRadioButton = new QRadioButton(fileGroupBox);
        txtRadioButton->setObjectName(QString::fromUtf8("txtRadioButton"));
        txtRadioButton->setGeometry(QRect(150, 30, 81, 25));
        txtRadioButton->setChecked(true);
        cameraGroupBox = new QGroupBox(centralwidget);
        cameraGroupBox->setObjectName(QString::fromUtf8("cameraGroupBox"));
        cameraGroupBox->setGeometry(QRect(910, 210, 581, 201));
        cameraXSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraXSpin->setObjectName(QString::fromUtf8("cameraXSpin"));
        cameraXSpin->setGeometry(QRect(10, 50, 151, 28));
        cameraZSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraZSpin->setObjectName(QString::fromUtf8("cameraZSpin"));
        cameraZSpin->setGeometry(QRect(420, 50, 151, 28));
        cameraYSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraYSpin->setObjectName(QString::fromUtf8("cameraYSpin"));
        cameraYSpin->setGeometry(QRect(210, 50, 161, 28));
        cameraAddPushbutton = new QPushButton(cameraGroupBox);
        cameraAddPushbutton->setObjectName(QString::fromUtf8("cameraAddPushbutton"));
        cameraAddPushbutton->setGeometry(QRect(440, 160, 131, 27));
        cameraListWidget = new QListWidget(cameraGroupBox);
        cameraListWidget->setObjectName(QString::fromUtf8("cameraListWidget"));
        cameraListWidget->setGeometry(QRect(10, 90, 256, 101));
        cameraSetPushbutton = new QPushButton(cameraGroupBox);
        cameraSetPushbutton->setObjectName(QString::fromUtf8("cameraSetPushbutton"));
        cameraSetPushbutton->setGeometry(QRect(280, 160, 131, 27));
        cameraDeletePushbutton = new QPushButton(cameraGroupBox);
        cameraDeletePushbutton->setObjectName(QString::fromUtf8("cameraDeletePushbutton"));
        cameraDeletePushbutton->setGeometry(QRect(280, 100, 131, 27));
        cameraMoveButton = new QPushButton(cameraGroupBox);
        cameraMoveButton->setObjectName(QString::fromUtf8("cameraMoveButton"));
        cameraMoveButton->setGeometry(QRect(440, 100, 131, 27));
        label_2 = new QLabel(cameraGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 66, 19));
        label_3 = new QLabel(cameraGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 30, 66, 19));
        label_4 = new QLabel(cameraGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 30, 66, 19));
        objectGroupBox = new QGroupBox(centralwidget);
        objectGroupBox->setObjectName(QString::fromUtf8("objectGroupBox"));
        objectGroupBox->setGeometry(QRect(910, 420, 581, 771));
        objectListWidget = new QListWidget(objectGroupBox);
        objectListWidget->setObjectName(QString::fromUtf8("objectListWidget"));
        objectListWidget->setGeometry(QRect(10, 40, 256, 291));
        objectListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        obkectMoveXSpin = new QDoubleSpinBox(objectGroupBox);
        obkectMoveXSpin->setObjectName(QString::fromUtf8("obkectMoveXSpin"));
        obkectMoveXSpin->setGeometry(QRect(20, 360, 161, 28));
        obkectMoveXSpin->setMinimum(-500.000000000000000);
        obkectMoveXSpin->setMaximum(500.000000000000000);
        objectScaleXSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleXSpin->setObjectName(QString::fromUtf8("objectScaleXSpin"));
        objectScaleXSpin->setGeometry(QRect(400, 360, 161, 28));
        objectScaleXSpin->setMinimum(-100.000000000000000);
        objectScaleXSpin->setMaximum(100.000000000000000);
        objectScaleXSpin->setValue(1.000000000000000);
        objectRotateXSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateXSpin->setObjectName(QString::fromUtf8("objectRotateXSpin"));
        objectRotateXSpin->setGeometry(QRect(210, 360, 161, 28));
        objectRotateXSpin->setMinimum(-360.000000000000000);
        objectRotateXSpin->setMaximum(360.000000000000000);
        objectMoveYSpin = new QDoubleSpinBox(objectGroupBox);
        objectMoveYSpin->setObjectName(QString::fromUtf8("objectMoveYSpin"));
        objectMoveYSpin->setGeometry(QRect(20, 440, 161, 28));
        objectMoveYSpin->setMinimum(-500.000000000000000);
        objectMoveYSpin->setMaximum(500.000000000000000);
        objectRotateYSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateYSpin->setObjectName(QString::fromUtf8("objectRotateYSpin"));
        objectRotateYSpin->setGeometry(QRect(210, 440, 161, 28));
        objectRotateYSpin->setMinimum(-360.000000000000000);
        objectRotateYSpin->setMaximum(360.000000000000000);
        objectScaleYSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleYSpin->setObjectName(QString::fromUtf8("objectScaleYSpin"));
        objectScaleYSpin->setGeometry(QRect(400, 440, 161, 28));
        objectScaleYSpin->setMinimum(-100.000000000000000);
        objectScaleYSpin->setMaximum(100.000000000000000);
        objectScaleYSpin->setValue(1.000000000000000);
        objectMoveZSpin = new QDoubleSpinBox(objectGroupBox);
        objectMoveZSpin->setObjectName(QString::fromUtf8("objectMoveZSpin"));
        objectMoveZSpin->setGeometry(QRect(20, 520, 161, 28));
        objectMoveZSpin->setMinimum(-500.000000000000000);
        objectMoveZSpin->setMaximum(500.000000000000000);
        objectRotateZSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateZSpin->setObjectName(QString::fromUtf8("objectRotateZSpin"));
        objectRotateZSpin->setGeometry(QRect(210, 520, 161, 28));
        objectRotateZSpin->setMinimum(-360.000000000000000);
        objectRotateZSpin->setMaximum(360.000000000000000);
        objectScaleZSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleZSpin->setObjectName(QString::fromUtf8("objectScaleZSpin"));
        objectScaleZSpin->setGeometry(QRect(400, 520, 161, 28));
        objectScaleZSpin->setMinimum(-100.000000000000000);
        objectScaleZSpin->setMaximum(100.000000000000000);
        objectScaleZSpin->setValue(1.000000000000000);
        objectDeletePushbutton = new QPushButton(objectGroupBox);
        objectDeletePushbutton->setObjectName(QString::fromUtf8("objectDeletePushbutton"));
        objectDeletePushbutton->setGeometry(QRect(290, 60, 271, 27));
        objectCompositePushbutton = new QPushButton(objectGroupBox);
        objectCompositePushbutton->setObjectName(QString::fromUtf8("objectCompositePushbutton"));
        objectCompositePushbutton->setGeometry(QRect(290, 110, 271, 27));
        label_5 = new QLabel(objectGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 340, 66, 19));
        label_6 = new QLabel(objectGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 340, 66, 19));
        label_7 = new QLabel(objectGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 340, 66, 19));
        label_8 = new QLabel(objectGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 420, 66, 19));
        label_9 = new QLabel(objectGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(400, 420, 66, 19));
        label_10 = new QLabel(objectGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 420, 66, 19));
        label_11 = new QLabel(objectGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(210, 500, 66, 19));
        label_12 = new QLabel(objectGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 500, 66, 19));
        label_13 = new QLabel(objectGroupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(400, 500, 66, 19));
        objectMovePushbutton = new QPushButton(objectGroupBox);
        objectMovePushbutton->setObjectName(QString::fromUtf8("objectMovePushbutton"));
        objectMovePushbutton->setGeometry(QRect(20, 590, 161, 27));
        objectRotatePushbutton = new QPushButton(objectGroupBox);
        objectRotatePushbutton->setObjectName(QString::fromUtf8("objectRotatePushbutton"));
        objectRotatePushbutton->setGeometry(QRect(210, 590, 161, 27));
        objectScalePushbutton = new QPushButton(objectGroupBox);
        objectScalePushbutton->setObjectName(QString::fromUtf8("objectScalePushbutton"));
        objectScalePushbutton->setGeometry(QRect(400, 590, 161, 27));
        logGroupBox = new QGroupBox(centralwidget);
        logGroupBox->setObjectName(QString::fromUtf8("logGroupBox"));
        logGroupBox->setGeometry(QRect(0, 900, 901, 291));
        logTextEdit = new QTextEdit(logGroupBox);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setGeometry(QRect(10, 40, 881, 201));
        logTextEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260", nullptr));
        typeGroupBOx->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        listRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272", nullptr));
        matrixRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260", nullptr));
        fileLineEdit->setText(QCoreApplication::translate("MainWindow", "./data/cube.txt", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        loadPushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        fileGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264 \320\244\320\260\320\271\320\273\320\260", nullptr));
        sqliteRadioButton->setText(QCoreApplication::translate("MainWindow", "Sqlite", nullptr));
        txtRadioButton->setText(QCoreApplication::translate("MainWindow", "Txt", nullptr));
        cameraGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", nullptr));
        cameraAddPushbutton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cameraSetPushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        cameraDeletePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        cameraMoveButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        objectGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        objectDeletePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
        objectCompositePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\262 \320\272\320\276\320\274\320\277\320\276\320\267\320\270\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ox", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Kx", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ky", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Oy", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Oz", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Kz", nullptr));
        objectMovePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        objectRotatePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        objectScalePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        logGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERFACE_H
