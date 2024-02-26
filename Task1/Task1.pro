
TEMPLATE = app
TARGET = app.exe
INCLUDEPATH += ./headers
QT += gui widgets opengl core
LIBS += -lGLU -lGL
OBJECTS_DIR = ./obj

# Input
HEADERS += headers/actions.h \
           headers/edges.h \
           headers/errs.h \
           headers/figure.h \
           headers/point.h \
           headers/points.h \
           headers/window.hpp \
           headers/myopengl.hpp

SOURCES += src/edges.c \
           src/figure.c \
           src/main.cpp \
           src/point.c \
           src/points.c \
           src/window.cpp \
           src/myopengl.cpp \
           src/actions.c
