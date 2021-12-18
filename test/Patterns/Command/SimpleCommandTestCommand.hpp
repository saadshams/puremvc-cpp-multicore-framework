#ifndef PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP
#define PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP

#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

class SimpleCommandTestCommand : SimpleCommand {
public:
    void execute(Notification *notification) override;

    ~SimpleCommandTestCommand() override;
};

#endif //PUREMVC_SIMPLECOMMANDTESTCOMMAND_HPP
