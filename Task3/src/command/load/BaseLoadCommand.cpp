#include "BaseLoadCommand.h"

BaseLoadCommand::~BaseLoadCommand(){}

size_t BaseLoadCommand::GetDirectorId(){ return _director_id; }

size_t BaseLoadCommand::GetReaderId(){ return _reader_id; }