#include "LiftDoors.h"
#include <iostream>

LiftDoors::LiftDoors() {
    _status = CLOSED;
    connect(&_openingTimer, SIGNAL(timeout()), this, SLOT(openSlot()));
    connect(&_closingTimer, SIGNAL(timeout()), this, SLOT(closeSlot()));
    connect(&_openedTimer, SIGNAL(timeout()), this, SLOT(closingSlot()));
}

void LiftDoors::openSlot() {
    if (_status == OPENING) {
        std::cout << "Двери открыты"  << std::endl;
        _status = OPEN;
        _openedTimer.start(OPENED_TIME);
    }
}


void LiftDoors::closeSlot() {
    if (_status == CLOSING) {
        _status = CLOSED;
        std::cout << "Двери закрыты" << std::endl;
        emit ClosedSignal();
    }
}

void LiftDoors::closingSlot() {
    if (_status == OPEN) {
        _status = CLOSING;
        std::cout << "Двери закрываются" << std::endl;
        _closingTimer.start(CLOSING_TIME);
    }
}

void LiftDoors::OpeningSlot() {
    if (_status == CLOSED || _status == CLOSING) {
        std::cout << "Двери открываются" << std::endl;
        _status = OPENING;
        auto remainingTime = _closingTimer.remainingTime();
        _closingTimer.stop();
        _openingTimer.start(OPENING_TIME - remainingTime);
    }
}