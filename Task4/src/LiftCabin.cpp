#include "LiftCabin.h"
#include <iostream>


LiftCabin::LiftCabin(QObject *parent) : QObject(parent) {
    _status = STAND;
    _currentFloor = 1;
    _targetFloor = 1;
    _direction = STOP;
    connect(this, SIGNAL(MoveSignal()), this, SLOT(moveSlot()));
    connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(moveSlot()));
    connect(&_doors, SIGNAL(ClosedSignal()), this, SLOT(moveSlot()));
    connect(this, SIGNAL(OpenDoorsSignal()), &_doors, SLOT(OpeningSlot()));
}

void LiftCabin::GetCommandSlot(size_t currentFloor, size_t targetFloor) {
    if (_status == STAND) {
        _status = GOTCOMMAND;
        _currentFloor = currentFloor;
        _targetFloor = targetFloor;
        _direction = _currentFloor > _targetFloor ? DOWN : UP;
        emit MoveSignal();
    }
}

void LiftCabin::moveSlot() {
    if (_status == PAUSE || _status == GOTCOMMAND)
        _status = MOVING;
    else
        _currentFloor += _direction;
    
    std::cout << "Лифт на " << _currentFloor << " этаже." << std::endl;

    _moveTimer.start(MOVETIME);
    emit FloorPassedSignal(_currentFloor, _direction); 
}

void LiftCabin::StopCabinSlot(size_t currentFloor, size_t neededFloor) {
    if (_status == MOVING) {
        _status = STAND;
        _currentFloor = currentFloor;
        _targetFloor = neededFloor;
        _direction = STOP;
        _moveTimer.stop();
        std::cout << "Лифт остановился на " << _currentFloor << " этаже." << std::endl;
    }
}

void LiftCabin::PauseCabinSlot(size_t currentFloor, size_t neededFloor) {
    if (_status == MOVING || _status == STAND) {
        _status = PAUSE;
        _currentFloor = currentFloor;
        _targetFloor = neededFloor;
        _direction = _currentFloor > _targetFloor ? DOWN : UP;
        _moveTimer.stop();
        std::cout << "Остановка на " << _currentFloor << " этаже." << std::endl;
        emit OpenDoorsSignal();
    }
}
