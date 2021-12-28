#include "Interfaces/Observer.hpp"
#include <utility>

using PureMVC::Patterns::Observer;
using PureMVC::Patterns::Notification;

Observer::Observer(std::function<void(Notification *)> notify, const void *context) {
    this->_notify = std::move(notify);
    this->_context = context;
}

void Observer::setNotifyContext(const void *context) {
    this->_context = context;
}

void Observer::setNotifyMethod(std::function<void(Notification *)> notify) {
    this->_notify = std::move(notify);
}

const void *Observer::getNotifyContext() const {
    return this->_context;
}

std::function<void(Notification *)> Observer::getNotifyMethod() {
    return this->_notify;
}

void Observer::notifyObserver(Notification *notification) {
    this->_notify(notification);
}

bool Observer::compareNotifyContext(const void *object) const {
    return this->_context == object;
}

Observer::~Observer() = default;
