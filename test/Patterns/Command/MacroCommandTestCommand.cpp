#include "MacroCommandTestCommand.hpp"
#include "MacroCommandTestSub1Command.hpp"
#include "MacroCommandTestSub2Command.hpp"

void MacroCommandTestCommand::initializeMacroCommand() {
    addSubCommand([]() { return (SimpleCommand*) new MacroCommandTestSub1Command(); });
    addSubCommand([]() { return (SimpleCommand*) new MacroCommandTestSub2Command(); });
}
