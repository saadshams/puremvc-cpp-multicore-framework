#include "Interfaces/MacroCommand.hpp"

using PureMVC::Patterns::MacroCommand;

MacroCommand::MacroCommand() = default;

void MacroCommand::initializeMacroCommand() {

}

void MacroCommand::addSubCommand(const std::function<SimpleCommand*()> &factory) {
    _subcommands.push_back(factory);
}

void MacroCommand::execute(Notification *notification) {
    this->initializeMacroCommand();
    auto iterator = _subcommands.begin();

    while (iterator != _subcommands.end()) {
        auto commandInstance = (*iterator)();
        // commandInstance->initializeNotifier(multitonKey);
        commandInstance->execute(notification);
        delete commandInstance;

        _subcommands.erase(iterator);
        iterator = _subcommands.begin();
    }
}

MacroCommand::~MacroCommand() {
    _subcommands.clear();
}
