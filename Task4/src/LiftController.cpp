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
    _floorsup = std::vector<bool>(FLOORS, true);
    _floorsdown = std::vector<bool>(FLOORS, true);
    _floorsin = std::vector<bool>(FLOORS, true);
    for (size_t i = 1; i <= FLOORS; i++) {
        std::shared_ptr<LiftButton> button(new LiftButton(i, UP));
        
        _upbuttons.push_back(button);
        connect(button.get(), SIGNAL(PressedSignal(size_t, Direction)), this, SLOT(ButtonPushedSlot(size_t, Direction)));
        connect(this, SIGNAL(CabinPauseSignal(size_t, size_t, Direction)), button.get(), SLOT(DoneButtonActionSlot(size_t, size_t, Direction)));
        _layout->addWidget(button.get(), FLOORS - i + 1, 0);
    }
    _layout->addWidget(new QLabel("Вверх"), 0, 0);
    
    for (size_t i = 1; i <= FLOORS; i++) {
        std::shared_ptr<LiftButton> button(new LiftButton(i, DOWN));
        
        _downbuttons.push_back(button);
        connect(button.get(), SIGNAL(PressedSignal(size_t, Direction)), this, SLOT(ButtonPushedSlot(size_t, Direction)));
        connect(this, SIGNAL(CabinPauseSignal(size_t, size_t, Direction)), button.get(), SLOT(DoneButtonActionSlot(size_t, size_t, Direction)));
        _layout->addWidget(button.get(), FLOORS - i + 1, 1);
    }
    _layout->addWidget(new QLabel("Вниз"), 0, 1);

    for (size_t i = 1; i <= FLOORS; i++) {
        std::shared_ptr<LiftButton> button(new LiftButton(i, BOTH));
        
        _inbuttons.push_back(button);
        connect(button.get(), SIGNAL(PressedSignal(size_t, Direction)), this, SLOT(ButtonPushedSlot(size_t, Direction)));
        connect(this, SIGNAL(CabinPauseSignal(size_t, size_t, Direction)), button.get(), SLOT(DoneButtonActionSlot(size_t, size_t, Direction)));
        _layout->addWidget(button.get(), FLOORS - i + 1, 2);
    }
    _layout->addWidget(new QLabel("Внутри лифта"), 0, 2);
}


void LiftController::ButtonPushedSlot(size_t floor, Direction direction) {
    if (direction == UP)
        _floorsup[floor - 1] = false;
    else if (direction == DOWN)
        _floorsdown[floor - 1] = false;
    else 
        _floorsin[floor - 1] = false;


    _status = BUTTONPUSHED;
    GetNextFloor(_targetFloor);

    if (!_floorsin[_currentFloor - 1]) {
        emit FloorReachedSignal(_currentFloor, _direction);
        return;
    }

    if (!_floorsup[_currentFloor - 1] and _direction == UP)
        emit FloorReachedSignal(_currentFloor, _direction);
    else if (!_floorsdown[_currentFloor - 1] and _direction == DOWN)
        emit FloorReachedSignal(_currentFloor, _direction);
    else
        emit GotTargetSignal(_currentFloor, _targetFloor);
}

void LiftController::FloorReachedSlot(size_t floor, Direction direction) {
    if (_status == BUSY || _status == BUTTONPUSHED) {
        _status = BUSY;
        _currentFloor = floor;
        _direction = direction;
        bool next = GetNextFloor(_targetFloor);

        if (!next) {
            emit ControllerStopSignal();
            return;
        }

        if (_currentFloor == _targetFloor) {
            _floorsdown[_currentFloor - 1] = true;
            _floorsup[_currentFloor - 1] = true;
            _floorsin[_currentFloor - 1] = true;
            GetNextFloor(_targetFloor);
            emit CabinPauseSignal(_currentFloor, _targetFloor, BOTH);
        } else if (_direction == DOWN && !_floorsdown[_currentFloor - 1]) {
            _floorsdown[_currentFloor - 1] = true;
            _floorsin[_currentFloor - 1] = true;
            emit CabinPauseSignal(_currentFloor, _targetFloor, _direction);
        } else if (_direction == UP && !_floorsup[_currentFloor - 1]) {
            _floorsup[_currentFloor - 1] = true;
            _floorsin[_currentFloor - 1] = true;
            emit CabinPauseSignal(_currentFloor, _targetFloor, _direction);
        } else if (!_floorsin[_currentFloor - 1]) {
            _floorsin[_currentFloor - 1] = true;
            emit CabinPauseSignal(_currentFloor, _targetFloor, _direction);
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
            if (!_floorsup[i - 1] || !_floorsdown[i - 1] || !_floorsin[i - 1]) {
                _direction = DOWN;
                found = i;
                return true;
            }
        }
        for (size_t i = FLOORS - 1; i > _currentFloor; i--) {
            if (!_floorsup[i - 1] || !_floorsdown[i - 1] || !_floorsin[i - 1]) {
                _direction = UP;
                found = i;
                return true;
            }
        }
    } else {
        for (size_t i = FLOORS - 1; i >= _currentFloor; i--) {
            if (!_floorsup[i - 1] || !_floorsdown[i - 1] || !_floorsin[i - 1]) {
                _direction = UP;
                found = i;
                return true;
            }
        }
        for (size_t i = 1; i < _currentFloor; i++) {
            if (!_floorsup[i - 1] || !_floorsdown[i - 1] || !_floorsin[i - 1]) {
                _direction = DOWN;
                found = i;
                return true;
            }
        }
    }
    return false;
}