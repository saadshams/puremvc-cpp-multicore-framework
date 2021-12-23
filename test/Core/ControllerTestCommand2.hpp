#ifndef PUREMVC_CONTROLLERTESTCOMMAND2_HPP
#define PUREMVC_CONTROLLERTESTCOMMAND2_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class ControllerTestCommand2 : public SimpleCommand {

    void execute(Notification *notification) override;

};


#endif //PUREMVC_CONTROLLERTESTCOMMAND2_HPP
