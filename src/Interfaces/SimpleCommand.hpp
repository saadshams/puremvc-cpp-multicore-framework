#ifndef PUREMVC_SIMPLECOMMAND_HPP
#define PUREMVC_SIMPLECOMMAND_HPP

#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::Observer::Notification;

namespace PureMVC::Patterns::Command {
    class SimpleCommand {
    public:
        virtual void execute(Notification *notification);

        virtual ~SimpleCommand();
    };
}

#endif //PUREMVC_SIMPLECOMMAND_HPP
