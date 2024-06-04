
TEMPLATE = app
TARGET = app.exe

QT += gui widgets core
OBJECTS_DIR = ./obj
LIBS += -lsqlite3
QMAKE_CXXFLAGS += -Werror -Wall -Wpedantic -std=c++20 -g -O0

INCLUDEPATH += \ 
inc/objects \ 
inc/transform \ 
inc/visitor \ 
inc/square_matrix \ 
inc/exception \ 
inc/builder \ 
inc/reader \ 
inc/strategy \ 
inc/director \ 
inc/concepts \ 
inc/manager \ 
inc/scene \ 
inc/drawer \
inc/command/ \
inc/command/draw \
inc/command/load \
inc/command/camera \
inc/command/scene \
inc/command/object \
inc/facade \


# Input
HEADERS += inc/builder/BaseBoneModelBuilder.h \
inc/builder/ListBoneModelBuilder.h \
inc/builder/MatrixBoneModelBuilder.h \
inc/concepts/concept.h \
inc/director/BaseBoneModelDirector.h \
inc/director/BaseDirectorCreator.h \
inc/director/BaseDirector.h \
inc/director/DirectorCreator.h \
inc/director/DirectorCreator.hpp \
inc/director/DirectorSolution.h \
inc/director/ListBoneModelDirector.h \
inc/director/MatrixBoneModelDirector.h \
inc/drawer/BaseDrawer.h \
inc/drawer/QtDrawer.h \
inc/drawer/BaseDrawerCreator.h \
inc/drawer/QtDrawerCreator.h \
inc/exception/baseexception.h \
inc/exception/directorexception.h \
inc/exception/managerexception.h \
inc/exception/matrixexception.h \
inc/exception/modelexception.h \
inc/exception/solutionexception.h \
inc/exception/sqlitereaderexception.h \
inc/exception/txtreaderexception.h \
inc/manager/LoadManager.h \
inc/manager/SceneManager.h \
inc/manager/DrawManager.h \
inc/manager/DrawManager.hpp \
inc/objects/BaseModel.h \
inc/objects/BoneModel.h \
inc/objects/Camera.h \
inc/objects/Composite.h \
inc/objects/Edge.h \
inc/objects/InvisibleObject.h \
inc/objects/ListModelStructure.h \
inc/objects/MatrixModelStructure.h \
inc/objects/ModelStructure.h \
inc/objects/Object.h \
inc/objects/Point.h \
inc/objects/VisibleObject.h \
inc/reader/BaseReaderCreator.h \
inc/reader/BaseReader.h \
inc/reader/BoneModelReader.h \
inc/reader/ReaderCreator.h \
inc/reader/ReaderCreator.hpp \
inc/reader/ReaderSolution.h \
inc/reader/SqliteBoneModelReader.h \
inc/reader/TxtBoneModelReader.h \
inc/scene/Scene.h \
inc/square_matrix/SquareMatrix.h \
inc/square_matrix/SquareMatrix.hpp \
inc/square_matrix/SquareMatrixRow.hpp \
inc/strategy/CenterStrategy.h \
inc/transform/RotateAction.h \
inc/transform/ScaleAction.h \
inc/transform/ShiftAction.h \
inc/transform/TransformAction.h \
inc/transform/CameraProjectionAction.h \
inc/visitor/Visitor.h \
inc/visitor/DrawVisitor.h \
src/mainwindow.hpp \
src/interface.hpp \
inc/facade/SceneFacade.h \
inc/command/draw/BaseDrawCommand.h \
inc/command/draw/DrawSceneQtCommand.h \
inc/command/load/TxtLoadCommandDecorator.h \
inc/command/load/BaseLoadCommand.h \
inc/command/load/MatrixLoadCommand.h \
inc/command/load/ListLoadCommand.h \
inc/command/load/SqliteLoadCommandDecorator.h \
inc/command/load/BaseLoadCommandDecorator.h \
inc/command/camera/SetCameraCommand.h \
inc/command/camera/MoveCameraCommand.h \
inc/command/camera/BaseCameraCommand.h \
inc/command/camera/RemoveCameraCommand.h \
inc/command/camera/AddCameraCommand.h \
inc/command/scene/ClearSceneCommand.h \
inc/command/scene/BaseSceneCommand.h \
inc/command/object/ScaleObjectCommand.h \
inc/command/object/BaseObjectCommand.h \
inc/command/object/ShiftObjectCommand.h \
inc/command/object/RotateObjectCommand.h \
inc/command/object/RemoveObjectCommand.h \
inc/command/object/CompositeObjectCommand.h \
inc/command/BaseCommand.h \
inc/command/scene/GetObjectIDsSceneCommand.h \
inc/command/scene/GetCameraIDsSceneCommand.h \




SOURCES += ./src/builder/BaseBoneModelBuilder.cpp \
./src/builder/ListBoneModelBuilder.cpp \
./src/builder/MatrixBoneModeBuilder.cpp \
./src/director/BaseBoneModelDirector.cpp \
./src/director/Basedirector.cpp \
./src/director/DirectorSolution.cpp \
./src/director/ListBoneModelDirector.cpp \
./src/director/MatrixBoneModelDirector.cpp \
./src/drawer/BaseDrawer.cpp \
./src/drawer/QtDrawer.cpp \
./src/drawer/BaseDrawerCreator.cpp \
./src/drawer/QtDrawerCreator.cpp \
./src/exception/baseexception.cpp \
./src/manager/LoadManager.cpp \
./src/manager/SceneManager.cpp \
./src/manager/TransformManager.cpp \
./src/objects/BaseModel.cpp \
./src/objects/BoneModel.cpp \
./src/objects/Camera.cpp \
./src/objects/Composite.cpp \
./src/objects/Edge.cpp \
./src/objects/InvisibleObject.cpp \
./src/objects/ListModelStructure.cpp \
./src/objects/MatrixModelStructure.cpp \
./src/objects/ModelStructure.cpp \
./src/objects/Object.cpp \
./src/objects/Point.cpp \
./src/objects/VisibleObject.cpp \
./src/reader/BaseReader.cpp \
./src/reader/BoneModelReader.cpp \
./src/reader/ReaderSolution.cpp \
./src/reader/SqliteBoneModelReader.cpp \
./src/reader/TxtBoneModelReader.cpp \
./src/scene/Scene.cpp \
./src/strategy/CenterStrategy.cpp \
./src/transform/RotateAction.cpp \
./src/transform/ScaleAction.cpp \
./src/transform/ShiftAction.cpp \
./src/transform/TransformAction.cpp \
./src/transform/CameraProjectionAction.cpp \
./src/visitor/DrawVisitor.cpp \
./src/main.cpp \
./src/mainwindow.cpp \
src/facade/SceneFacade.cpp \
src/command/BaseCommand.cpp  \ 
src/command/camera/SetCameraCommand.cpp  \
src/command/camera/MoveCameraCommand.cpp  \
src/command/camera/BaseCameraCommand.cpp  \
src/command/camera/AddCameraCommand.cpp  \
src/command/camera/RemoveCameraCommand.cpp  \
src/command/draw/BaseDrawCommand.cpp  \
src/command/draw/DrawSceneQtCommand.cpp  \
src/command/load/MatrixLoadCommand.cpp  \
src/command/load/SqliteLoadCommandDecorator.cpp  \
src/command/load/ListLoadCommand.cpp  \
src/command/load/BaseLoadCommand.cpp  \
src/command/load/BaseLoadCommandDecorator.cpp  \
src/command/load/TxtLoadCommandDecorator.cpp  \
src/command/object/BaseObjectCommand.cpp  \
src/command/object/RotateObjectCommand.cpp  \
src/command/object/ShiftObjectCommand.cpp  \
src/command/object/ScaleObjectCommand.cpp  \
src/command/object/RemoveObjectCommand.cpp  \
src/command/object/CompositeObjectCommand.cpp  \
src/command/scene/ClearSceneCommand.cpp  \
src/command/scene/BaseSceneCommand.cpp  \
src/command/scene/GetObjectIDsSceneCommand.cpp  \
src/command/scene/GetCameraIDsSceneCommand.cpp  \