#ifndef PUREMVC_CONTROLLERTESTCOMMAND_HPP
#define PUREMVC_CONTROLLERTESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class ControllerTestCommand : public SimpleCommand {
    void execute(Notification *notification) override;
};

#endif //PUREMVC_CONTROLLERTESTCOMMAND_HPP
