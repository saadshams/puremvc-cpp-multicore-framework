#include "Interfaces/Notifier.hpp"
#include "Interfaces/Facade.hpp"

using PureMVC::Patterns::Facade;
using PureMVC::Patterns::Notifier;

void Notifier::initializeNotifier(const std::string &key) {
    multitonKey = key;
}

void Notifier::sendNotification(const std::string &name, const void *body, const std::string &type) {
    getFacade()->sendNotification(name, body, type);
}

void Notifier::sendNotification(const std::string &name, const void *body) {
    getFacade()->sendNotification(name, body, "");
}

void Notifier::sendNotification(const std::string &name) {
    getFacade()->sendNotification(name, nullptr, "");
}

Facade *Notifier::getFacade() {
    return Facade::getInstance(multitonKey, [](const std::string &k) { return new Facade(k); });
}

Notifier::~Notifier() = default;
