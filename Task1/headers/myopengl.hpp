#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
extern "C" {
    #include "figure.h"
    #include "errs.h"
}


class OGLWidget : public QOpenGLWidget
{
public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();
    myerror_t move(move_t *act);
    myerror_t rotate(rotate_t *act);
    myerror_t scale(scale_t *act);
    myerror_t read(const char *fname);
    myerror_t write(const char *fname);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    figure_t *fig;
};

#endif // OGLWIDGET_H

