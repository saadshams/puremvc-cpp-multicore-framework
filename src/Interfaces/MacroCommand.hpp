#ifndef PUREMVC_MACROCOMMAND_HPP
#define PUREMVC_MACROCOMMAND_HPP

#include "SimpleCommand.hpp"
#include "Notification.hpp"
#include <list>

using PureMVC::Patterns::Command::SimpleCommand;
using PureMVC::Patterns::Observer::Notification;

namespace PureMVC::Patterns::Command {
    class MacroCommand {
    private:
        std::list<SimpleCommand* (*)()> _subcommands;
    protected:
        virtual void initializeMacroCommand();

        virtual void addSubCommand(SimpleCommand* (*factory)());
    public:
        explicit MacroCommand();

        virtual void execute(Notification *notification) final;

        ~MacroCommand();
    };
}

#endif //PUREMVC_MACROCOMMAND_HPP
