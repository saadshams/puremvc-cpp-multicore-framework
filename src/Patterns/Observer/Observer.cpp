#include "Interfaces/Observer.hpp"
#include <utility>

using PureMVC::Patterns::Observer;
using PureMVC::Patterns::Notification;

Observer::Observer(std::function<void(Notification *)> notify, const void *context) {
    this->notify = std::move(notify);
    this->context = context;
}

void Observer::setNotifyContext(const void *context) {
    this->context = context;
}

void Observer::setNotifyMethod(std::function<void(Notification *)> notify) {
    this->notify = std::move(notify);
}

const void *Observer::getNotifyContext() const {
    return this->context;
}

std::function<void(Notification *)> Observer::getNotifyMethod() {
    return this->notify;
}

void Observer::notifyObserver(Notification *notification) {
    this->notify(notification);
}

bool Observer::compareNotifyContext(const void *object) const {
    return this->context == object;
}

Observer::~Observer() = default;
