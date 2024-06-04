#include "CameraProjectionAction.h"
#include "Camera.h"
#include "ShiftAction.h"

CameraProjectionAction::CameraProjectionAction(std::shared_ptr<Camera> camera) : TransformAction(), _camera(camera) {
    ShiftAction toCenter(Point(-camera->_self.GetX(), -camera->_self.GetY(), -camera->_self.GetZ()));
    SquareMatrix<double> toCameraBasis(4);
    
    toCameraBasis[0][0] = camera->_normalRight.GetX() - camera->_self.GetX();
    toCameraBasis[1][0] = camera->_normalRight.GetY() - camera->_self.GetY();
    toCameraBasis[2][0] = camera->_normalRight.GetZ() - camera->_self.GetZ();
    toCameraBasis[3][0] = 0;

    toCameraBasis[0][1] = camera->_normalUp.GetX() - camera->_self.GetX();
    toCameraBasis[1][1] = camera->_normalUp.GetY() - camera->_self.GetY();
    toCameraBasis[2][1] = camera->_normalUp.GetZ() - camera->_self.GetZ();
    toCameraBasis[3][1] = 0;

    toCameraBasis[0][2] = camera->_normalForward.GetX() - camera->_self.GetX();
    toCameraBasis[1][2] = camera->_normalForward.GetY() - camera->_self.GetY();
    toCameraBasis[2][2] = camera->_normalForward.GetZ() - camera->_self.GetZ();
    toCameraBasis[3][2] = 0;
    toCameraBasis[3][3] = 1;

    _matrix *= toCenter.GetMatrix();
    _matrix *= toCameraBasis;
}

