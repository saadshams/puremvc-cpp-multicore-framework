#ifndef PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP
#define PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class MacroCommandTestSub2Command : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP
