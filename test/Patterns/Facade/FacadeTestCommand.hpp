#ifndef PUREMVC_FACADETESTCOMMAND_HPP
#define PUREMVC_FACADETESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notification;

class FacadeTestCommand : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_FACADETESTCOMMAND_HPP
