#include "ControllerTestCommand.hpp"
#include "ControllerTestVO.hpp"

void ControllerTestCommand::execute(Notification *notification) {
    auto vo = (ControllerTestVO *) notification->getBody();

    vo->result = 2 * vo->input;
}
