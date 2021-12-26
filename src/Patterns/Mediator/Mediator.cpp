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

std::vector<std::string> Mediator::listNotificationInterests() {
    return {};
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
