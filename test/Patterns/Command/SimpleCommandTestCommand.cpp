#include "SimpleCommandTestCommand.hpp"
#include "SimpleCommandTestVO.hpp"

void SimpleCommandTestCommand::execute(Notification *notification) {
    auto *vo = (SimpleCommandTestVO *) notification->getBody();
    vo->result = 2 * vo->input;
}

SimpleCommandTestCommand::~SimpleCommandTestCommand() = default;