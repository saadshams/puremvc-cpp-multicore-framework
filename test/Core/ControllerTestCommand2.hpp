#ifndef PUREMVC_CONTROLLERTESTCOMMAND2_HPP
#define PUREMVC_CONTROLLERTESTCOMMAND2_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class ControllerTestCommand2 : public SimpleCommand {
    void execute(Notification *notification) override;
};

#endif //PUREMVC_CONTROLLERTESTCOMMAND2_HPP
