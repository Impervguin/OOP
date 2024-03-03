
TEMPLATE = app
TARGET = app.exe
INCLUDEPATH += ./headers
QT += gui widgets core
OBJECTS_DIR = ./obj


# Input
HEADERS += headers/actions.h \
           headers/edges.h \
           headers/errs.h \
           headers/figure.h \
           headers/point.h \
           headers/points.h \
           headers/window.hpp \
           headers/projection.h \
           headers/draw.hpp \
           headers/interface.hpp

SOURCES += src/edges.c \
           src/figure.c \
           src/main.cpp \
           src/point.c \
           src/points.c \
           src/window.cpp \
           src/actions.c \
           src/errs.c \
           src/projection.c \
           src/draw.cpp \
           src/interface.cpp
