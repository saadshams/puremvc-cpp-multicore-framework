#include "Interfaces/View.hpp"

using PureMVC::Core::View;

View::View(const std::string &key) {
    if (_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
    _instanceMap[key] = this;
}

View *View::getInstance(const std::string &key, View *(*factory)(const std::string &k)) {
    if (!_instanceMap.contains(key)) _instanceMap[key] = factory(key);
    _instanceMap[key]->initializeView();
    return _instanceMap[key];
}

void View::initializeView() {

}

void View::registerMediator(Mediator *mediator) {
    if (_mediatorMap.contains(mediator->getMediatorName())) return;

    // mediator->initializeNotifier(_multitonKey);

    _mediatorMap[mediator->getMediatorName()] = mediator;

    auto interests = mediator->listNotificationInterests();
}

Mediator *View::retrieveMediator(const std::string &mediatorName) {
    return _mediatorMap[mediatorName];
}

Mediator *View::removeMediator(const std::string &mediatorName) {
    auto *mediator = _mediatorMap[mediatorName];
    if (mediator) {
        auto interests = mediator->listNotificationInterests();
        // for (const char *const *cursor = interests; *cursor != nullptr; cursor++) {
            // removeObserver(cursor, mediator);
        // }
        _mediatorMap.erase(mediatorName);
        mediator->onRemove();
    }
    return mediator;
}

bool View::hasMediator(const std::string &mediatorName) {
    return _mediatorMap.contains(mediatorName);
}

View::~View() = default;
