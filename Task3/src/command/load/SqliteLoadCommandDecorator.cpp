#include "SqliteLoadCommandDecorator.h"

SqliteLoadCommandDecorator::SqliteLoadCommandDecorator(BaseLoadCommand &command, const char *filename)
: BaseLoadCommandDecorator(command), _filename(filename) {
    _command = command;
    _reader_id = SQLITEBONEMODELREADERCREATOR_ID;
}
void SqliteLoadCommandDecorator::Execute() {
    _command.Execute();
    _director_id = _command.GetDirectorId();
    auto obj = _loadManager->LoadBoneModelFile(_director_id, _reader_id, _filename);
    _sceneManager->AddObject(obj);
};