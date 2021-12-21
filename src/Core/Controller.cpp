#include "Interfaces/Controller.hpp"

using PureMVC::Core::Controller;

Controller::Controller(const std::string &key) {
    if (_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
    _instanceMap[key] = this;
}

Controller *Controller::getInstance(const std::string &key, Controller *(*factory)(std::string)) {
    if (!_instanceMap.contains(key)) _instanceMap[key] = factory(key);
    _instanceMap[key]->initializeController();
    return Controller::_instanceMap[key];
}

void Controller::initializeController() {
    // view.getInstance
}

void Controller::executeCommand(Notification *notification) {
    auto *commandInstance = _commandMap[notification->getName()]();
    // commandInstance.initializeNotifier(_multitonKey);
    commandInstance->execute(notification);
}

void Controller::registerCommand(const std::string &notificationName, SimpleCommand *(*factory)()) {
    if (!_commandMap.contains(notificationName)) {
        // view.registerObserver
    }
    _commandMap[notificationName] = factory;
}

bool Controller::hasCommand(const std::string &notificationName) {
    return _commandMap.contains(notificationName);
}

void Controller::removeCommand(const std::string &notificationName) {
    if (hasCommand(notificationName)) {
        // view.removeObserver();

        _commandMap.erase(notificationName);
    }
}

void Controller::removeController(const std::string &key) {
    _instanceMap.erase(key);
}

Controller::~Controller() {
    removeController(_multitonKey);
    _commandMap.clear();
}
