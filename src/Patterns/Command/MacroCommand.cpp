#include "Interfaces/MacroCommand.hpp"

using PureMVC::Patterns::MacroCommand;

MacroCommand::MacroCommand() = default;

void MacroCommand::initializeMacroCommand() {

}

void MacroCommand::addSubCommand(const std::function<SimpleCommand *()> &factory) {
    subcommands.push_back(factory);
}

void MacroCommand::execute(Notification *notification) {
    this->initializeMacroCommand();
    auto iterator = subcommands.begin();

    while (iterator != subcommands.end()) {
        auto commandInstance = (*iterator)();
        commandInstance->initializeNotifier(multitonKey);
        commandInstance->execute(notification);

        delete commandInstance;
        subcommands.erase(iterator);
        iterator = subcommands.begin();
    }
}

MacroCommand::~MacroCommand() {
    subcommands.clear();
}
