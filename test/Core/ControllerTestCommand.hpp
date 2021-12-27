#ifndef PUREMVC_CONTROLLERTESTCOMMAND_HPP
#define PUREMVC_CONTROLLERTESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class ControllerTestCommand : public SimpleCommand {

    void execute(Notification *notification) override;

};

#endif //PUREMVC_CONTROLLERTESTCOMMAND_HPP
