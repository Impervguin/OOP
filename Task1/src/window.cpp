#include "window.hpp"
#include <QPushButton>
#include <cstdlib>


Window::Window(QWidget *parent) :
 QWidget(parent)
 {
 // Set size of the window
 setFixedSize(1000, 1000);

 // Create and position the button
    scaleBox = new QGroupBox("Scale box", this);
    scaleBox->setGeometry(620, 0, 110, 500);

    // scaleLabel = new QLabel("<center>Scale</center>", scaleBox);
    // scaleLabel->setGeometry(5, 60, 100, 48);
    
    scalexLabel = new QLabel("X:", scaleBox);
    scalexLabel->setGeometry(5, 60, 25, 48);

    xScaleInp = new QDoubleSpinBox(scaleBox);
    xScaleInp->setGeometry(30, 60, 75, 48);

    scaleyLabel = new QLabel("Y:", scaleBox);
    scaleyLabel->setGeometry(5, 168, 25, 48);

    yScaleInp = new QDoubleSpinBox(scaleBox);
    yScaleInp->setGeometry(30, 168, 75, 48);

    scalezLabel = new QLabel("Z:", scaleBox);
    scalezLabel->setGeometry(5, 276, 25, 48);

    zScaleInp = new QDoubleSpinBox(scaleBox);
    zScaleInp->setGeometry(30, 276, 75, 48);

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

    rotateyLabel = new QLabel("oY:", rotateBox);
    rotateyLabel->setGeometry(5, 168, 25, 48);

    yrotateInp = new QDoubleSpinBox(rotateBox);
    yrotateInp->setGeometry(30, 168, 75, 48);

    rotatezLabel = new QLabel("oZ:", rotateBox);
    rotatezLabel->setGeometry(5, 276, 25, 48);

    zrotateInp = new QDoubleSpinBox(rotateBox);
    zrotateInp->setGeometry(30, 276, 75, 48);

    rotateButton = new QPushButton("Rotate", rotateBox);
    rotateButton->setGeometry(5, 412, 100, 48);

 // Create and position the button
    moveBox = new QGroupBox("Move box", this);
    moveBox->setGeometry(870, 0, 110, 500);
    
    movexLabel = new QLabel("X:", moveBox);
    movexLabel->setGeometry(5, 60, 25, 48);

    xmoveInp = new QDoubleSpinBox(moveBox);
    xmoveInp->setGeometry(30, 60, 75, 48);

    moveyLabel = new QLabel("Y:", moveBox);
    moveyLabel->setGeometry(5, 168, 25, 48);

    ymoveInp = new QDoubleSpinBox(moveBox);
    ymoveInp->setGeometry(30, 168, 75, 48);

    movezLabel = new QLabel("Z:", moveBox);
    movezLabel->setGeometry(5, 276, 25, 48);

    zmoveInp = new QDoubleSpinBox(moveBox);
    zmoveInp->setGeometry(30, 276, 75, 48);

    moveButton = new QPushButton("Move", moveBox);
    moveButton->setGeometry(5, 412, 100, 48);

    // Load
    loadBox = new QGroupBox("Load box", this);
    loadBox->setGeometry(600, 500, 200, 500);

    loadLabel = new QLabel("Load file:", loadBox);
    loadLabel->setGeometry(5, 100, 190, 25);

    loadLine = new QLineEdit(loadBox);
    loadLine->setGeometry(5, 125, 190, 30);

    loadButton = new QPushButton("Save figure", loadBox);
    loadButton->setGeometry(50, 300, 100, 30);
    // Save
    saveBox = new QGroupBox("Save box", this);
    saveBox->setGeometry(800, 500, 200, 500);

    saveLabel = new QLabel("Save file:", saveBox);
    saveLabel->setGeometry(5, 100, 190, 25);

    saveLine = new QLineEdit(saveBox);
    saveLine->setGeometry(5, 125, 190, 30);

    saveButton = new QPushButton("Save figure", saveBox);
    saveButton->setGeometry(50, 300, 100, 30);

    drawwwww = new OGLWidget(this);
    drawwwww->setGeometry(0,0, 600, 600);
//  fig = init_figure();
//  read_figure("./data/cube.txt", fig);
//  m_button = new QPushButton("Hello World", this);
//  m_button->setGeometry(10, 10, 80, 30);
//  lable = new QLabel("HIIIIII", this);
//  lable->setGeometry(90, 90, 100, 100);
//  connect(m_button, &QPushButton::clicked, this, &Window::butt_click);
}

// void Window::butt_click()
// {
//     // printf("HIIIIIII %d\n", a);
//     write_figure("test", fig);
//     clear_figure(fig);
// }