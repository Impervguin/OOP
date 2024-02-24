#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "figure.h"

class OGLWidget : public QOpenGLWidget
{
public:
    OGLWidget(QWidget *parent = 0, figure_t *figure = NULL);
    ~OGLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    figure_t *fig;
};

#endif // OGLWIDGET_H

