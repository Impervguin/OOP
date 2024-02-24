#include "myopengl.hpp"

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::initializeGL()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex3d(1.000000, 1.000000, 1.000000);
        glVertex3d(1.000000, 1.000000, -1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(1.000000, 1.000000, 1.000000);
        glVertex3d(1.000000, -1.000000, 1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(1.000000, 1.000000, 1.000000);
        glVertex3d(-1.000000, 1.000000, 1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(-1.000000, 1.000000, 1.000000);
        glVertex3d(-1.000000, 1.000000, -1.000000);
        // glColor3f(1, 1, 1);  
        glVertex3d(-1.000000, 1.000000, 1.000000);
        glVertex3d(-1.000000, -1.000000, 1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(-1.000000, -1.000000, -1.000000);
        glVertex3d(-1.000000, 1.000000, -1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(-1.000000, -1.000000, -1.000000);
        glVertex3d(1.000000, -1.000000, -1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(-1.000000, -1.000000, -1.000000);
        glVertex3d(-1.000000, -1.000000, 1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(1.000000, 1.000000, -1.000000);
        glVertex3d(-1.000000, 1.000000, -1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(1.000000, 1.000000, -1.000000);
        glVertex3d(1.000000, -1.000000, -1.000000);
        // glColor3f(1, 1, 1);
        glVertex3d(1, -1, 1);
        glVertex3d(-1, -1, 1);
        // glColor3f(1, 1, 1);
        glVertex3d(1.000000, -1.000000, -1.000000);
        glVertex3d(1.000000, -1.000000, 1.000000);
    glEnd();

    // glBegin(GL_LINES);
    //     glColor3f(1, 1, 1);
    //     glVertex3d(1, 1, 1);
    //     glVertex3d(1,)
    // glEnd();
    // glBegin(GL_2D)
}

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
}