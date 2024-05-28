#include "LiftButton.h"


LiftButton::LiftButton(size_t floor, QWidget *parent) :  QPushButton(parent), _status(UNPRESSED), _floor(floor) {
    connect(this, SIGNAL(clicked()), this, SLOT(pressedButtonSlot()));
    connect(this, SIGNAL(DoneButtonActionSignal()), this, SLOT(DoneButtonActionSlot()));

    this->setText(QString::number(floor));
}

void LiftButton::pressedButtonSlot() {
    if (_status == UNPRESSED) {
        _status = PRESSED;
        this->setDisabled(true);
        emit PressedSignal(_floor);
    }
}

void LiftButton::DoneButtonActionSlot() {
    if (_status == PRESSED) {
        _status = UNPRESSED;
        this->setDisabled(false);
    }
}

