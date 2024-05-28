#pragma once
#include "LiftButton.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>


#include <vector>
#include <memory>

#define FLOORS 9

enum Direction {
    UP = 1,
    STOP = 0,
    DOWN = -1
};

class LiftController : public QWidget {
    Q_OBJECT

    enum LiftControllerStatus {
        IDLE,
        BUTTONPUSHED,
        BUSY
    };

    public:
        LiftController(QWidget *parent = 0);
        ~LiftController() = default;

    public slots:
        void ButtonPushedSlot(size_t floor);
        void FloorReachedSlot(size_t floor, Direction direction);
        void ControllerStopSlot();
    
    signals:
        void ControllerStopSignal();
        void FloorReachedSignal(size_t floor, Direction direction);
        void GotTargetSignal(size_t currentFloor, size_t neededFloor);
        void CabinStopSignal(size_t currentFloor, size_t neededFloor);
        void CabinPauseSignal(size_t currentFloor, size_t neededFloor);
        


    private:
        std::vector<std::shared_ptr<LiftButton>> _inbuttons;
        std::vector<std::shared_ptr<LiftButton>> _outbuttons;

        LiftControllerStatus _status;
        size_t _currentFloor;
        size_t _targetFloor;

        Direction _direction;

        std::vector<bool> _floors;

        std::unique_ptr<QGridLayout> _layout;

        bool GetNextFloor(size_t &found); 
};