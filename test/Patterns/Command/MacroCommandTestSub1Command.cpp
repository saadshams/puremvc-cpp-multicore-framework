#include "MacroCommandTestSub1Command.hpp"
#include "MacroCommandTestVO.hpp"

void MacroCommandTestSub1Command::execute(Notification *notification) {
    auto *vo = (MacroCommandTestVO *) notification->getBody();

    vo->result1 = 2 * vo->input;
}
