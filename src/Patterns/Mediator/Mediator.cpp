#include "Interfaces/Mediator.h"

using PureMVC::Patterns::Mediator;

Mediator::Mediator(const string& mediatorName, const void* viewComponent) {
    _mediatorName = mediatorName;
    _viewComponent = viewComponent;
}

void Mediator::onRegister() {

}

void Mediator::onRemove() {

}

const char *const *Mediator::listNotificationInterests() {
    static const char * const interests[] = {nullptr};
    return interests;
}

string Mediator::getMediatorName() {
    return _mediatorName;
}

void Mediator::setViewComponent(const void *viewComponent) {
    _viewComponent = viewComponent;
}

const void *Mediator::getViewComponent() {
    return _viewComponent;
}

Mediator::~Mediator() = default;
