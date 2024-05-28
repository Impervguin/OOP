#pragma once
#include <QPushButton>

class LiftButton : public QPushButton {
    Q_OBJECT

    enum LiftButtonStatus {
        PRESSED,
        UNPRESSED
    };

    public:
        LiftButton(size_t floor, QWidget *parent = 0);
        ~LiftButton() = default;

    public slots:
        void DoneButtonActionSlot();
    private slots:
        void pressedButtonSlot();
    
    signals:
        void PressedSignal(size_t floor);
        void DoneButtonActionSignal();
    
    private:
        LiftButtonStatus _status;
        size_t _floor;
};