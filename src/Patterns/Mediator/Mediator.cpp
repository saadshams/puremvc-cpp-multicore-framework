#include "Interfaces/Mediator.hpp"

using PureMVC::Patterns::Mediator;

Mediator::Mediator(const std::string &mediatorName, const void *viewComponent) {
    this->mediatorName = mediatorName;
    this->viewComponent = viewComponent;
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
    return this->mediatorName;
}

void Mediator::setViewComponent(const void *viewComponent) {
    this->viewComponent = viewComponent;
}

const void *Mediator::getViewComponent() const {
    return this->viewComponent;
}

Mediator::~Mediator() = default;
