#include "ListLoadCommand.h"

ListLoadCommand::ListLoadCommand() {
    _director_id = LISTBONEMODELDIRECTORCREATOR_ID;
}
void ListLoadCommand::Execute() {
    _director_id = LISTBONEMODELDIRECTORCREATOR_ID;
};