#include "ScaleObjectCommand.h"

ScaleObjectCommand::ScaleObjectCommand(std::size_t id, double kx, double ky, double kz)
: _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleObjectCommand::Execute() {
    auto obj = _sceneManager->GetObject(_id);
    _transformManager->ScaleObject(obj, _kx, _ky, _kz);
}