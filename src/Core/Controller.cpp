#include "Interfaces/Controller.hpp"

using PureMVC::Core::Controller;

Controller::Controller(const std::string &key) {
    if (_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
    _instanceMap[key] = this;
    _view = nullptr;
}

Controller *Controller::getInstance(const std::string &key, const std::function<Controller *(const std::string &k)> &factory) {
    if (!_instanceMap.contains(key)) _instanceMap[key] = factory(key);
    _instanceMap[key]->initializeController();
    return _instanceMap[key];
}

void Controller::initializeController() {
    _view = View::getInstance(_multitonKey, [](const std::string &k) { return new View(k); });
}

void Controller::executeCommand(Notification *notification) {
    if (_commandMap.contains(notification->getName())) {
        auto *commandInstance = _commandMap[notification->getName()]();
        // commandInstance.initializeNotifier(_multitonKey);
        commandInstance->execute(notification);
    }
}

void Controller::registerCommand(const std::string &notificationName, std::function<SimpleCommand *()> factory) {
    if (!_commandMap.contains(notificationName)) {
        std::function<void(Notification *)> handler = [this](Notification *note) { executeCommand(note); };
        _view->registerObserver(notificationName, new Observer(handler, this));
    }
    _commandMap[notificationName] = factory;
}

bool Controller::hasCommand(const std::string &notificationName) const {
    return _commandMap.contains(notificationName);
}

void Controller::removeCommand(const std::string &notificationName) {
    if (hasCommand(notificationName)) {
        _view->removeObserver(notificationName, this);
        _commandMap.erase(_commandMap.find(notificationName));
    }
}

void Controller::removeController(const std::string &key) {
    _instanceMap.erase(_instanceMap.find(key));
}

Controller::~Controller() {
    removeController(_multitonKey);
    _commandMap.clear();
}
