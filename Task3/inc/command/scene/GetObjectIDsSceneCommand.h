#pragma once
#include "BaseSceneCommand.h"

class GetObjectIDsSceneCommand : public BaseSceneCommand {
    public:
        GetObjectIDsSceneCommand();
        virtual ~GetObjectIDsSceneCommand() = default;

        virtual void Execute();
        std::vector<std::size_t> GetIDs();
    private:
        std::vector<std::size_t> _ids;
};