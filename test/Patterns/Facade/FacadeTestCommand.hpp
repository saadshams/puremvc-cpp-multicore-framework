#ifndef PUREMVC_FACADETESTCOMMAND_HPP
#define PUREMVC_FACADETESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class FacadeTestCommand : public SimpleCommand {
public:
    void execute(Notification *notification) override;
};

#endif //PUREMVC_FACADETESTCOMMAND_HPP
