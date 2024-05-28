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
    if (_status == STAND || _status == GOTCOMMAND)
        _status = MOVING;
    else
        _currentFloor += _direction;
    
    std::cout << "Лифт на " << _currentFloor << " этаже." << std::endl;

    if (_currentFloor != _targetFloor) {
        _moveTimer.start(MOVETIME);
    } else {
        StopCabinSlot(false, _currentFloor, _targetFloor);
    }
    emit FloorPassedSignal(_currentFloor, _direction); 
}

void LiftCabin::StopCabinSlot(bool openDoors, size_t currentFloor, size_t neededFloor) {
    (void) openDoors;
    if (_status == STAND || _status == MOVING) {
        _status = STAND;
        _currentFloor = currentFloor;
        _targetFloor = neededFloor;
        _direction = _currentFloor > _targetFloor ? DOWN : UP;
        _moveTimer.stop();
        std::cout << "Остановка на " << _currentFloor << " этаже." << std::endl;
        if (openDoors)
            emit OpenDoorsSignal();
    }
}
