#include "BaseObjectCommand.h"

class CompositeObjectCommand : public BaseObjectCommand {
    public:
        CompositeObjectCommand() = delete;
        virtual ~CompositeObjectCommand() = default;
        CompositeObjectCommand(std::vector<size_t> ids);

        virtual void Execute();


    private:
        std::vector<size_t> _ids;
};