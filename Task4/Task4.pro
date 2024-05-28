
TEMPLATE = app
TARGET = app.exe

QT += gui widgets core
OBJECTS_DIR = ./obj
QMAKE_CXXFLAGS += -Werror -Wall -Wpedantic -std=c++20 -g -O0

INCLUDEPATH += inc/


# Input
HEADERS += inc/mainwindow.h \
inc/LiftController.h \
inc/LiftButton.h \
inc/Lift.h \
inc/LiftCabin.h \
inc/LiftDoors.h \




SOURCES += src/LiftController.cpp \
src/Lift.cpp \
src/main.cpp \
src/mainwindow.cpp \
src/LiftDoors.cpp \
src/LiftCabin.cpp \
src/LiftButton.cpp \