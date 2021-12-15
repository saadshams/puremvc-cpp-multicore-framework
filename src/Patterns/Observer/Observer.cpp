#include "Interfaces/Observer.hpp"

using PureMVC::Patterns::Observer::Observer;
using PureMVC::Patterns::Observer::Notification;

Observer::Observer(void (*notify)(Notification *notification), const void *context) {
    this->_notify = notify;
    this->_context = context;
}

void Observer::setNotifyContext(const void *context) {
    this->_context = context;
}

void Observer::setNotifyMethod(void (*notify)(Notification *notification)) {
    this->_notify = notify;
}

const void* Observer::getNotifyContext() {
    return this->_context;
}

void (*Observer::getNotifyMethod())(Notification*) {
    return this->_notify;
}

void Observer::notifyObserver(Notification *notification) {
    this->_notify(notification);
}

bool Observer::compareNotifyContext(const void* object) {
    return this->_context == object;
}

Observer::~Observer() = default;
