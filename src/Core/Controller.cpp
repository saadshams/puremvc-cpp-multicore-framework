#include "Interfaces/Controller.hpp"

using PureMVC::Core::Controller;

Controller::Controller(const std::string &key) {
    if (instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    multitonKey = key;
    instanceMap[key] = this;
    view = nullptr;
}

Controller *Controller::getInstance(const std::string &key, const std::function<Controller *(const std::string &k)> &factory) {
    if (!instanceMap.contains(key)) {
        instanceMap[key] = factory(key);
        instanceMap[key]->initializeController();
    }
    return instanceMap[key];
}

void Controller::initializeController() {
    view = View::getInstance(multitonKey, [](const std::string &k) { return new View(k); });
}

void Controller::executeCommand(Notification *notification) {
    if (commandMap.contains(notification->getName())) {
        auto factory = commandMap[notification->getName()];
        if (factory == nullptr) return;
        auto *commandInstance = factory();
        commandInstance->initializeNotifier(multitonKey);
        commandInstance->execute(notification);
    }
}

void Controller::registerCommand(const std::string &notificationName, const std::function<SimpleCommand *()> &factory) {
    if (!commandMap.contains(notificationName)) {
        view->registerObserver(notificationName, new Observer([this](Notification *notification) {
            executeCommand(notification);
        }, this));
    }
    commandMap[notificationName] = factory;
}

bool Controller::hasCommand(const std::string &notificationName) const {
    return commandMap.contains(notificationName);
}

void Controller::removeCommand(const std::string &notificationName) {
    if (hasCommand(notificationName)) {
        view->removeObserver(notificationName, this);
        commandMap.erase(commandMap.find(notificationName));
    }
}

void Controller::removeController(const std::string &key) {
    instanceMap.erase(instanceMap.find(key));
}

Controller::~Controller() {
    removeController(multitonKey);
    commandMap.clear();
}
