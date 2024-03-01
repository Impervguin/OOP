// Opengl is now forbidden in this lab, so this file is not used

#include "myopengl.hpp"
#include <cmath>

extern "C" {
    #include "figure.h"
    // #include "actions.h"
}

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    fig = create_figure();
}

OGLWidget::~OGLWidget()
{
    clear_figure(fig);
    free(fig);
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
        for (size_t i = 0; i < fig->edges.size; ++i)
        {
            glVertex3d(fig->points.arr[fig->edges.arr[i].p1].x,fig->points.arr[fig->edges.arr[i].p1].y,fig->points.arr[fig->edges.arr[i].p1].z);
            glVertex3d(fig->points.arr[fig->edges.arr[i].p2].x,fig->points.arr[fig->edges.arr[i].p2].y,fig->points.arr[fig->edges.arr[i].p2].z);
        }
    glEnd();

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


myerror_t OGLWidget::rotate(rotate_t *act)
{
    if (!fig)
        return OK;
    return rotate_figure(fig, act);
}

myerror_t OGLWidget::move(move_t *act)
{
    if (!fig)
        return OK;
    return move_figure(fig, act);
}

myerror_t OGLWidget::scale(scale_t *act)
{
    if (!fig)
        return OK;
    return scale_figure(fig, act);
}

myerror_t OGLWidget::read(const char *fname)
{
    if (!fname)
        return ERR_NULL_POINTER;
    return read_figure(fig, fname);
}

myerror_t OGLWidget::write(const char *fname)
{
    if (!fname)
        return ERR_NULL_POINTER;
    return write_figure(fname, fig);
}