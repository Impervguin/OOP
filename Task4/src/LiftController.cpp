#include "LiftController.h"
#include <iostream>


LiftController::LiftController(QWidget *parent) : QWidget(parent) {
    _layout = std::unique_ptr<QGridLayout>(new QGridLayout);
    this->setLayout(_layout.get());
    
    connect(this, SIGNAL(FloorReachedSignal(size_t, Direction)), this, SLOT(FloorReachedSlot(size_t, Direction)));
    connect(this, SIGNAL(ControllerStopSignal()), this, SLOT(ControllerStopSlot()));

    _status = IDLE;
    _currentFloor = 1;
    _targetFloor = 1;
    _direction = STOP;
    _floors = std::vector<bool>(FLOORS, true);
    for (size_t i = 1; i <= FLOORS; i++) {
        std::shared_ptr<LiftButton> button(new LiftButton(i));
        
        _inbuttons.push_back(button);
        connect(button.get(), SIGNAL(PressedSignal(size_t)), this, SLOT(ButtonPushedSlot(size_t)));
        _layout->addWidget(button.get(), FLOORS - i + 1, 0);
    }
    _layout->addWidget(new QLabel("Внутренние кнопки"), 0, 0);
    for (size_t i = 1; i <= FLOORS; i++) {
        std::shared_ptr<LiftButton> button(new LiftButton(i));
        
        _outbuttons.push_back(button);
        connect(button.get(), SIGNAL(PressedSignal(size_t)), this, SLOT(ButtonPushedSlot(size_t)));
        _layout->addWidget(button.get(), FLOORS - i + 1, 1);
    }
    _layout->addWidget(new QLabel("Внешние кнопки"), 0, 1);
}


void LiftController::ButtonPushedSlot(size_t floor) {
    _floors[floor - 1] = false;

    _status = BUTTONPUSHED;
    GetNextFloor(_targetFloor);

    if (!_floors[_currentFloor - 1])
        emit FloorReachedSignal(_currentFloor, _direction);
    else
        emit GotTargetSignal(_currentFloor, _targetFloor);
}

void LiftController::FloorReachedSlot(size_t floor, Direction direction) {
    if (_status == BUSY || _status == BUTTONPUSHED) {
        _status = BUSY;
        _currentFloor = floor;
        _direction = direction;

        if (!GetNextFloor(_targetFloor)) {
            
            emit ControllerStopSignal();
        }

        if (!_floors[_currentFloor - 1]) {
            _inbuttons[_currentFloor - 1]->DoneButtonActionSlot();
            _outbuttons[_currentFloor - 1]->DoneButtonActionSlot();
            _floors[_currentFloor - 1] = true;
            emit CabinPauseSignal( _currentFloor, _targetFloor);  
        }
    }
}

void LiftController::ControllerStopSlot() {
    if (_status == BUSY) {
        _status = IDLE;
        _direction = STOP;
        _targetFloor = _currentFloor;
        emit CabinStopSignal(_currentFloor, _targetFloor);
    }
}

bool LiftController::GetNextFloor(size_t &found) {
    if (_direction == STOP || _direction == DOWN) {
        for (size_t i = 1; i <= _currentFloor; i++) {
            if (!_floors[i - 1]) {
                _direction = DOWN;
                found = i;
                return true;
            }
        }
        for (size_t i = FLOORS - 1; i > _currentFloor; i--) {
            if (!_floors[i - 1]) {
                _direction = UP;
                found = i;
                return true;
            }
        }
    } else {
        for (size_t i = FLOORS - 1; i > _currentFloor; i--) {
            if (!_floors[i - 1]) {
                _direction = UP;
                found = i;
                return true;
            }
        }
        for (size_t i = 1; i <= _currentFloor; i++) {
            if (!_floors[i - 1]) {
                _direction = DOWN;
                found = i;
                return true;
            }
        }
    }
    return false;
}