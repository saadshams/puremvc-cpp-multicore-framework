#ifndef PUREMVC_SIMPLECOMMAND_HPP
#define PUREMVC_SIMPLECOMMAND_HPP

#include "Notification.hpp"
#include "Notifier.hpp"

using PureMVC::Patterns::Notifier;

namespace PureMVC::Patterns {
    class SimpleCommand : public Notifier {
    public:
        virtual void execute(Notification *notification);

        virtual ~SimpleCommand();
    };
}

#endif //PUREMVC_SIMPLECOMMAND_HPP
