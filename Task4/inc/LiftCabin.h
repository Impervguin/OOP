#pragma once
#include "LiftController.h"
#include "LiftDoors.h"
#include <QObject>
#include <QTimer>

#define MOVETIME 2000

class LiftCabin : public QObject {
    Q_OBJECT

    enum ListCabinStatus {
        STAND,
        GOTCOMMAND,
        MOVING
    };

    public:
        LiftCabin(QObject *parent = 0);
        ~LiftCabin() = default;
    
    public slots:
        void GetCommandSlot(size_t currentFloor, size_t neededFloor);
        void StopCabinSlot(bool openDoors, size_t currentFloor, size_t neededFloor);

    private:
        Direction _direction;
        size_t _currentFloor;
        size_t _targetFloor;
        ListCabinStatus _status;
        LiftDoors _doors;

        QTimer _moveTimer;
    
    private slots:
        void moveSlot();
    
    signals:
        void FloorPassedSignal(size_t floor, Direction direction);
        void OpenDoorsSignal();
        void MoveSignal();
};