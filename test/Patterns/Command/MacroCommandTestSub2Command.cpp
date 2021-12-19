#include "MacroCommandTestSub2Command.hpp"
#include "MacroCommandTestVO.hpp"

void MacroCommandTestSub2Command::execute(Notification *notification) {
    auto *vo = (MacroCommandTestVO *) notification->getBody();

    vo->result2 = vo->input * vo->input;
}
