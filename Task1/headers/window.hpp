#ifndef WINDOW_H
#define WINDOW_H

extern "C" {
    #include "actions.h"
    #include "figure.h"
    #include "errs.h"
}

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGroupBox>

class QPushButton;
class Window : public QWidget
{
    public:
        explicit Window(QWidget *parent = 0);
    private:
        // Scale
        QGroupBox *scaleBox;
        QPushButton *scaleButton;
        QDoubleSpinBox *xScaleInp;
        QDoubleSpinBox *yScaleInp;
        QDoubleSpinBox *zScaleInp;
        QLabel *scalexLabel;
        QLabel *scaleyLabel;
        QLabel *scalezLabel;
        // Move
        QGroupBox *moveBox;
        QPushButton *moveButton;
        QDoubleSpinBox *xmoveInp;
        QDoubleSpinBox *ymoveInp;
        QDoubleSpinBox *zmoveInp;
        QLabel *movexLabel;
        QLabel *moveyLabel;
        QLabel *movezLabel;
        // Rotate
        QGroupBox *rotateBox;
        QPushButton *rotateButton;
        QDoubleSpinBox *xrotateInp;
        QDoubleSpinBox *yrotateInp;
        QDoubleSpinBox *zrotateInp;
        QLabel *rotatexLabel;
        QLabel *rotateyLabel;
        QLabel *rotatezLabel;
        // Load
        QGroupBox *loadBox;
        QLabel *loadLabel;
        QLineEdit *loadLine;
        QPushButton *loadButton;
        // Save
        QGroupBox *saveBox;
        QLabel *saveLabel;
        QLineEdit *saveLine;
        QPushButton *saveButton;

//  private slots:
//   void butt_click();
};

#endif // WINDOW_H
