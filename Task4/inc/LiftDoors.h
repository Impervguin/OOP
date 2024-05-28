#pragma once
#include <QObject>
#include <QTimer>

#define OPENING_TIME 1000
#define CLOSING_TIME 1000
#define OPENED_TIME 1000


class LiftDoors : public QObject {
    Q_OBJECT

    enum LiftDoorsStatus {
        CLOSED,
        OPENING,
        OPEN,
        CLOSING
    };

    public:
        LiftDoors();
        ~LiftDoors() = default;
    
    public slots:
        void OpeningSlot();
    
    private slots:
        void openSlot();
        void closingSlot();
        void closeSlot();
    
    signals:
        void ClosedSignal();

    private:
        LiftDoorsStatus _status;

        QTimer _openingTimer;
        QTimer _closingTimer;
        QTimer _openedTimer;
};