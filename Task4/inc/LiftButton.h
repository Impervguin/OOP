#pragma once
#include <QPushButton>

enum Direction {
    UP = 1,
    STOP = 0,
    DOWN = -1,
    BOTH = 0
};

class LiftButton : public QPushButton {
    Q_OBJECT

    enum LiftButtonStatus {
        PRESSED,
        UNPRESSED
    };

    public:
        LiftButton(size_t floor, Direction direction, QWidget *parent = 0);
        ~LiftButton() = default;

    public slots:
        void DoneButtonActionSlot(size_t floor, size_t targetFloor, Direction direction);
    private slots:
        void pressedButtonSlot();
    
    signals:
        void PressedSignal(size_t floor, Direction direction);
        // void DoneButtonActionSignal();
    
    private:
        LiftButtonStatus _status;
        Direction _direction;
        size_t _floor;
};
