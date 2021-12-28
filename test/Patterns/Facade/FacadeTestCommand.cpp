#include "FacadeTestCommand.hpp"
#include "FacadeTestVO.hpp"

void FacadeTestCommand::execute(Notification *notification) {
    auto vo = (FacadeTestVO *) notification->getBody();
    vo->result = 2 * vo->input;
}
