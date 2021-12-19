#ifndef PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP
#define PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class MacroCommandTestSub1Command : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP
