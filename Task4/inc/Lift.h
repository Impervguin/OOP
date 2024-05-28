#pragma once

#include <QObject>

#include "LiftController.h"
#include "LiftCabin.h"


class Lift : public QObject {
    Q_OBJECT

    public:
        Lift(QObject *parent = nullptr);
        ~Lift() = default;

        QWidget *GetWidget();

    private:
        LiftController _controller;
        LiftCabin _cabin;
};