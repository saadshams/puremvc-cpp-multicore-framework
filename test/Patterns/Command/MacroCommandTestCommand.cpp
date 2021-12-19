#include "MacroCommandTestCommand.hpp"
#include "MacroCommandTestSub1Command.hpp"
#include "MacroCommandTestSub2Command.hpp"

inline SimpleCommand* NewMacroCommandTestSub1Command() {
    return new MacroCommandTestSub1Command();
}

inline SimpleCommand* NewMacroCommandTestSub2Command() {
    return new MacroCommandTestSub2Command();
}

void MacroCommandTestCommand::initializeMacroCommand() {
    addSubCommand(NewMacroCommandTestSub1Command);
    addSubCommand(NewMacroCommandTestSub2Command);
}
