#include "Interfaces/Notifier.hpp"
#include "Interfaces/Facade.hpp"

using PureMVC::Patterns::Facade;
using PureMVC::Patterns::Notifier;

void Notifier::initializeNotifier(const std::string &key) {
    _multitonKey = key;
}

void Notifier::sendNotification(const std::string &notificationName, const void *body, const std::string &type) {
    getFacade()->sendNotification(notificationName, body, type);
}

Facade *Notifier::getFacade() {
    return Facade::getInstance(_multitonKey, [](const std::string &k) { return new Facade(k); });
}
