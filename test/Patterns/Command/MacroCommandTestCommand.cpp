#include "MacroCommandTestCommand.hpp"
#include "MacroCommandTestSub1Command.hpp"
#include "MacroCommandTestSub2Command.hpp"

void MacroCommandTestCommand::initializeMacroCommand() {
    addSubCommand([]() -> SimpleCommand * { return new MacroCommandTestSub1Command(); });
    addSubCommand([]() -> SimpleCommand * { return new MacroCommandTestSub2Command(); });
}
