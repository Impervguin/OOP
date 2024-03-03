#include "window.hpp"
#include "actions.h"
#include "draw.hpp"
#include <QString>
#include <QPushButton>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <QGraphicsScene>

Window::Window(QWidget *parent) :
 QWidget(parent)
 {
 // Set size of the window
 setFixedSize(1000, 800);

 // Create and position the button
    scaleBox = new QGroupBox("Scale box", this);
    scaleBox->setGeometry(620, 0, 110, 500);

    // scaleLabel = new QLabel("<center>Scale</center>", scaleBox);
    // scaleLabel->setGeometry(5, 60, 100, 48);
    
    scalexLabel = new QLabel("X:", scaleBox);
    scalexLabel->setGeometry(5, 60, 25, 48);

    xScaleInp = new QDoubleSpinBox(scaleBox);
    xScaleInp->setGeometry(30, 60, 75, 48);
    xScaleInp->setRange(-5, 5);
    xScaleInp->setValue(1);

    scaleyLabel = new QLabel("Y:", scaleBox);
    scaleyLabel->setGeometry(5, 168, 25, 48);

    yScaleInp = new QDoubleSpinBox(scaleBox);
    yScaleInp->setGeometry(30, 168, 75, 48);
    yScaleInp->setRange(-5, 5);
    yScaleInp->setValue(1);

    scalezLabel = new QLabel("Z:", scaleBox);
    scalezLabel->setGeometry(5, 276, 25, 48);

    zScaleInp = new QDoubleSpinBox(scaleBox);
    zScaleInp->setGeometry(30, 276, 75, 48);
    zScaleInp->setRange(-5, 5);
    zScaleInp->setValue(1);

    scaleButton = new QPushButton("Scale", scaleBox);
    scaleButton->setGeometry(5, 412, 100, 48);


// Create and position the button
    rotateBox = new QGroupBox("Rotate box", this);
    rotateBox->setGeometry(745, 0, 110, 500);

    // rotateLabel = new QLabel("<center>rotate</center>", rotateBox);
    // rotateLabel->setGeometry(5, 60, 100, 48);
    
    rotatexLabel = new QLabel("oX:", rotateBox);
    rotatexLabel->setGeometry(5, 60, 25, 48);

    xrotateInp = new QDoubleSpinBox(rotateBox);
    xrotateInp->setGeometry(30, 60, 75, 48);
    xrotateInp->setRange(-360, 360);

    rotateyLabel = new QLabel("oY:", rotateBox);
    rotateyLabel->setGeometry(5, 168, 25, 48);

    yrotateInp = new QDoubleSpinBox(rotateBox);
    yrotateInp->setGeometry(30, 168, 75, 48);
    yrotateInp->setRange(-360, 360);

    rotatezLabel = new QLabel("oZ:", rotateBox);
    rotatezLabel->setGeometry(5, 276, 25, 48);

    zrotateInp = new QDoubleSpinBox(rotateBox);
    zrotateInp->setGeometry(30, 276, 75, 48);
    zrotateInp->setRange(-360, 360);

    rotateButton = new QPushButton("Rotate", rotateBox);
    rotateButton->setGeometry(5, 412, 100, 48);

 // Create and position the button
    moveBox = new QGroupBox("Move box", this);
    moveBox->setGeometry(870, 0, 110, 500);
    
    movexLabel = new QLabel("X:", moveBox);
    movexLabel->setGeometry(5, 60, 25, 48);

    xmoveInp = new QDoubleSpinBox(moveBox);
    xmoveInp->setGeometry(30, 60, 75, 48);
    xmoveInp->setRange(-5, 5);

    moveyLabel = new QLabel("Y:", moveBox);
    moveyLabel->setGeometry(5, 168, 25, 48);

    ymoveInp = new QDoubleSpinBox(moveBox);
    ymoveInp->setGeometry(30, 168, 75, 48);
    ymoveInp->setRange(-5, 5);

    movezLabel = new QLabel("Z:", moveBox);
    movezLabel->setGeometry(5, 276, 25, 48);

    zmoveInp = new QDoubleSpinBox(moveBox);
    zmoveInp->setGeometry(30, 276, 75, 48);
    zmoveInp->setRange(-5, 5);

    moveButton = new QPushButton("Move", moveBox);
    moveButton->setGeometry(5, 412, 100, 48);

    // Load
    loadBox = new QGroupBox("Load box", this);
    loadBox->setGeometry(600, 500, 200, 300);

    loadLabel = new QLabel("Load file:", loadBox);
    loadLabel->setGeometry(5, 100, 190, 25);

    loadLine = new QLineEdit(loadBox);
    loadLine->setGeometry(5, 125, 190, 30);
    loadLine->setText("./data/cube.txt");

    loadButton = new QPushButton("Load figure", loadBox);
    loadButton->setGeometry(50, 250, 100, 30);
    // Save
    saveBox = new QGroupBox("Save box", this);
    saveBox->setGeometry(800, 500, 200, 300);

    saveLabel = new QLabel("Save file:", saveBox);
    saveLabel->setGeometry(5, 100, 190, 25);

    saveLine = new QLineEdit(saveBox);
    saveLine->setGeometry(5, 125, 190, 30);

    saveButton = new QPushButton("Save figure", saveBox);
    saveButton->setGeometry(50, 250, 100, 30);

    fig = create_figure();
    printf("%p\n",fig);

    connect(rotateButton, &QPushButton::clicked, this, &Window::rotate_click);
    connect(moveButton, &QPushButton::clicked, this, &Window::move_click);
    connect(scaleButton, &QPushButton::clicked, this, &Window::scale_click);
    connect(loadButton, &QPushButton::clicked, this, &Window::load_click);
    connect(saveButton, &QPushButton::clicked, this, &Window::save_click);

    // drawwwww = new OGLWidget(this);
    // drawwwww->setGeometry(0,0, 600, 600);

    
    draw = new QGraphicsView(this);
    draw->setGeometry(0, 0, 600, 600);
    draw->setScene(new QGraphicsScene(draw));
    draw->scene()->setSceneRect(0, 0, 600, 600);

    // Log
    logBox = new QGroupBox("Log", this);
    logBox->setGeometry(0, 600, 600, 200);

    logText = new QTextEdit(logBox);
    logText->setGeometry(25, 25, 550, 170);
    logText->setTextInteractionFlags(Qt::NoTextInteraction);
    logString = new QString("");
    
}

void Window::draw_f() {
    auto rcontent = draw->contentsRect();
    draw->scene()->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    draw_t req = {
        draw->scene(),
        rcontent.width(),
        rcontent.height()
    };
    myerror_t err =  draw_figure(req, *fig);
}

void Window::rotate_click()
{
    double oy = degrees_to_radians(yrotateInp->value());
    double ox = degrees_to_radians(xrotateInp->value());
    double oz = degrees_to_radians(zrotateInp->value());
    rotate_t act = {.ox = ox, .oy = oy, .oz = oz};
    myerror_t err = rotate_figure(fig, &act);
    draw_f();
}

void Window::scale_click()
{
    double sx = xScaleInp->value();
    double sy = yScaleInp->value();
    double sz = zScaleInp->value();
    scale_t act = {.x = sx, .y = sy, .z = sz};
    myerror_t err = scale_figure(fig, &act);
    draw_f();
}

void Window::move_click()
{
    double x = xmoveInp->value();
    double y = ymoveInp->value();
    double z = zmoveInp->value();
    move_t act = {.x = x, .y = y, .z = z};
    myerror_t err = move_figure(fig, &act);
    draw_f();
}

void Window::load_click()
{
    std::string str = loadLine->text().toStdString();
    const char* fname = str.c_str();
    myerror_t err = read_figure(fig, fname);
    draw_f();
}

void Window::save_click()
{
    std::string str = saveLine->text().toStdString();
    const char* fname = str.c_str();
    myerror_t err = write_figure(fname, fig);
    draw_f();
}

void Window::log(const char *str)
{
    char tmp[strlen(str) + 2];
    strcpy(tmp, str);
    strcat(tmp, "\n");
    logString->append(tmp);
    QString& t = *logString;
    logText->setText(t);
}