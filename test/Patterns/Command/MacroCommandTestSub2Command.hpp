#ifndef PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP
#define PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class MacroCommandTestSub2Command : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_MACROCOMMANDTESTSUB2COMMAND_HPP
