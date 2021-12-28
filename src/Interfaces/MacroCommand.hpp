#ifndef PUREMVC_MACROCOMMAND_HPP
#define PUREMVC_MACROCOMMAND_HPP

#include <list>
#include "Notifier.hpp"
#include "Notification.hpp"
#include "SimpleCommand.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Patterns::Notifier;
using PureMVC::Patterns::Notification;

namespace PureMVC::Patterns {
    class MacroCommand : public Notifier {
    private:
        std::list<std::function<SimpleCommand *()>> _subcommands;
    protected:
        virtual void initializeMacroCommand();

        virtual void addSubCommand(const std::function<SimpleCommand *()> &factory);

    public:
        explicit MacroCommand();

        virtual void execute(Notification *notification) final;

        ~MacroCommand();
    };
}

#endif //PUREMVC_MACROCOMMAND_HPP
