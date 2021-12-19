#ifndef PUREMVC_MACROCOMMANDTESTCOMMAND_HPP
#define PUREMVC_MACROCOMMANDTESTCOMMAND_HPP

#include "Interfaces/MacroCommand.hpp"

using PureMVC::Patterns::Command::MacroCommand;

class MacroCommandTestCommand:public MacroCommand {
public:
    void initializeMacroCommand() override;
};

#endif //PUREMVC_MACROCOMMANDTESTCOMMAND_HPP
