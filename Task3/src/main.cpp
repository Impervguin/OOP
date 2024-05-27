// #include "../inc/objects/BoneModel.h"
// #include "../inc/objects/ListModelStructure.h"
// #include "../inc/visitor/Visitor.h"
// #include "ShiftAction.h"
// #include "ScaleAction.h"
// #include "RotateAction.h"
// #include "ReaderCreator.h"
// #include "ReaderSolution.h"
// #include "DirectorSolution.h"
// #include "BaseBoneModelDirector.h"
// #include "ListBoneModelBuilder.h"
// #include "LoadManager.h"
// #include "DrawManager.h"
// #include <iostream>
// #include <fstream>
// #include <cmath>
// #include <sqlite3.h>
// #include <QWidget>
// #include <QApplication>
// #include <QGraphicsView>
// #include <QGraphicsScene>
// #include "QtDrawerCreator.h"


// class MyWindow : public QWidget
// {
//     public:
//         QGraphicsView *draw;
//         explicit MyWindow(QWidget *parent = 0) : QWidget(parent) {
//             setFixedSize(800, 600);
//             setWindowTitle(QString::fromUtf8("3D Model Viewer"));
            
//             draw = new QGraphicsView(this);
//             draw->setGeometry(0, 0, 600, 600);
//             draw->setScene(new QGraphicsScene(draw));
//             draw->scene()->setSceneRect(0, 0, 600, 600);


//             LoadManager manager;
//             ScaleAction saction(100, 100, 100);
//             RotateAction action(45, 45, 0);

//             auto model = manager.LoadBoneModelFile(LISTBONEMODELDIRECTORCREATOR_ID, TXTBONEMODELREADERCREATOR_ID, "./data/stulc.txt");
//             model->Transform(saction);
//             model->Transform(action);
//             DrawManager drawmanager;
//             SceneManager sceneManager;
//             // std::shared_ptr<Scene> scene = std::make_shared<Scene>();
//             // scene->AddObject(model);
//             sceneManager.AddObject(model);
//             auto cam = std::make_shared<Camera>(-300, -300, -300);
//             drawmanager.DrawScene<QtDrawerCreator, QGraphicsScene*>(sceneManager.GetScene(), cam, draw->scene());
//         }
//         ~MyWindow() = default;
// };

// int main(int argc, char **argv)
// {
//     // SquareMatrix<int> mat;
//     // mat.Resize(4, false);
//     // mat[0][0] = true;

//     // for (size_t i = 0; i < 4; i++) {
//     //     for (auto it = mat[i].begin(); it != mat[i].end(); ++it) {
//     //         std::cout << *it << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }
 
//     QApplication app (argc, argv);

//     MyWindow window;
//     window.show();

//     return app.exec();
// }

#include "mainwindow.hpp"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    MyMainWindow window;
    window.show();

    return app.exec();
}