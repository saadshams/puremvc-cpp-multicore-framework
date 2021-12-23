#include "ControllerTestCommand2.hpp"
#include "ControllerTestVO.hpp"

void ControllerTestCommand2::execute(Notification *notification) {
    auto vo = (ControllerTestVO *) notification->getBody();

    vo->result = vo->result + (2 * vo->input);
}
