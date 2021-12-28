#ifndef PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP
#define PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class MacroCommandTestSub1Command : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_MACROCOMMANDTESTSUB1COMMAND_HPP
