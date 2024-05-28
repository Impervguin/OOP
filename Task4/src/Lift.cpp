#include "Lift.h"

Lift::Lift(QObject *parent) : QObject(parent) {
    connect(&_cabin, SIGNAL(FloorPassedSignal(size_t, Direction)), &_controller, SLOT(FloorReachedSlot(size_t, Direction)));
    connect(&_controller, SIGNAL(GotTargetSignal(size_t,size_t)), &_cabin, SLOT(GetCommandSlot(size_t,size_t)));
    connect(&_controller, SIGNAL(CabinStopSignal(size_t,size_t)), &_cabin, SLOT(StopCabinSlot(size_t,size_t)));
    connect(&_controller, SIGNAL(CabinPauseSignal(size_t,size_t)), &_cabin, SLOT(PauseCabinSlot(size_t,size_t)));
}

QWidget *Lift::GetWidget() {
    return &_controller;
}