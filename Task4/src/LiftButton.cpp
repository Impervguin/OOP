#include "LiftButton.h"


LiftButton::LiftButton(size_t floor, Direction direction, QWidget *parent) :  QPushButton(parent), _status(UNPRESSED), _direction(direction), _floor(floor) {
    connect(this, SIGNAL(clicked()), this, SLOT(pressedButtonSlot()));
    // connect(this, SIGNAL(DoneButtonActionSignal()), this, SLOT(DoneButtonActionSlot()));
    QString label;
    if (_direction == UP) {
        label = "UP";
    } else if (_direction == DOWN) {
        label = "DOWN";
    } else {
        label = "";
    }
    this->setText(QString::number(floor) + QString(" ") + label);
}

void LiftButton::pressedButtonSlot() {
    if (_status == UNPRESSED) {
        _status = PRESSED;
        this->setDisabled(true);
        emit PressedSignal(_floor, _direction);
    }
}

void LiftButton::DoneButtonActionSlot(size_t floor, size_t targetFloor, Direction direction) {
    (void) targetFloor;
    if (_status == PRESSED) {
        if (((_direction == direction || _direction == BOTH || direction == BOTH) && (floor == _floor))) {
            _status = UNPRESSED;
            this->setDisabled(false);
        }
    }
}

