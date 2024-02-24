#include "myopengl.hpp"

OGLWidget::OGLWidget(QWidget *parent, figure_t *figure)
    : QOpenGLWidget(parent)
{
    fig = figure;
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
        for (size_t i = 0; i < fig->edges.size; i++)
        {
            glVertex3d(fig->points.arr[fig->edges.arr[i].p1].x,fig->points.arr[fig->edges.arr[i].p1].y,fig->points.arr[fig->edges.arr[i].p1].z);
            glVertex3d(fig->points.arr[fig->edges.arr[i].p2].x,fig->points.arr[fig->edges.arr[i].p2].y,fig->points.arr[fig->edges.arr[i].p2].z);
        }
        // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, 1.000000, 1.000000);
        // glVertex3d(1.000000, 1.000000, -1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, 1.000000, 1.000000);
        // glVertex3d(1.000000, -1.000000, 1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, 1.000000, 1.000000);
        // glVertex3d(-1.000000, 1.000000, 1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(-1.000000, 1.000000, 1.000000);
        // glVertex3d(-1.000000, 1.000000, -1.000000);
        // // glColor3f(1, 1, 1);  
        // glVertex3d(-1.000000, 1.000000, 1.000000);
        // glVertex3d(-1.000000, -1.000000, 1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(-1.000000, -1.000000, -1.000000);
        // glVertex3d(-1.000000, 1.000000, -1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(-1.000000, -1.000000, -1.000000);
        // glVertex3d(1.000000, -1.000000, -1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(-1.000000, -1.000000, -1.000000);
        // glVertex3d(-1.000000, -1.000000, 1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, 1.000000, -1.000000);
        // glVertex3d(-1.000000, 1.000000, -1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, 1.000000, -1.000000);
        // glVertex3d(1.000000, -1.000000, -1.000000);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1, -1, 1);
        // glVertex3d(-1, -1, 1);
        // // glColor3f(1, 1, 1);
        // glVertex3d(1.000000, -1.000000, -1.000000);
        // glVertex3d(1.000000, -1.000000, 1.000000);
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
    gluLookAt(-5,0,0,0,0,0,0,0,1);
}