#ifndef PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP
#define PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class SimpleCommandTestCommand : SimpleCommand {
public:
    void execute(Notification *notification) override;

    ~SimpleCommandTestCommand() override;
};

#endif //PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP
