#include "Interfaces/Mediator.hpp"

using PureMVC::Patterns::Mediator;

Mediator::Mediator(const std::string &mediatorName, const void *viewComponent) {
    this->_mediatorName = mediatorName;
    this->_viewComponent = viewComponent;
}

void Mediator::onRegister() {

}

void Mediator::onRemove() {

}

const char *const *Mediator::listNotificationInterests() {
    static const char *const interests[] = {nullptr};
    return interests;
}

void Mediator::handleNotification(Notification *notification) {

}

const std::string &Mediator::getMediatorName() const {
    return this->_mediatorName;
}

void Mediator::setViewComponent(const void *viewComponent) {
    this->_viewComponent = viewComponent;
}

const void *Mediator::getViewComponent() const {
    return this->_viewComponent;
}

Mediator::~Mediator() = default;
