#include "Interfaces/View.hpp"

using PureMVC::Core::View;

View::View(const std::string &key) {
    if (_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
    _instanceMap[key] = this;
}

View *View::getInstance(const std::string &key, const std::function<View *(const std::string &k)> &factory) {
    if (!_instanceMap.contains(key)) _instanceMap[key] = factory(key);
    _instanceMap[key]->initializeView();
    return _instanceMap[key];
}

void View::initializeView() {

}

void View::registerObserver(const std::string &notificationName, Observer *observer) {
    _observerMap[notificationName].push_back(observer);
}

void View::notifyObservers(Notification *notification) {
    if (_observerMap.contains(notification->getName())) {
        auto observers = _observerMap[notification->getName()];

        std::for_each(observers.begin(), observers.end(), [notification](auto *observer) {
            observer->notifyObserver(notification);
        });
    }
}

void View::removeObserver(const std::string &notificationName, const void *notifyContext) {
    auto observers = _observerMap[notificationName];

    for (unsigned int i = 0; i < observers.size(); i++) {
        if (observers[i]->compareNotifyContext(notifyContext)) {
            observers.erase(observers.begin() + i);
            break;
        }
    }

    if (observers.empty()) {
        _observerMap.erase(_observerMap.find(notificationName));
    }
}

void View::registerMediator(Mediator *mediator) {
    if (_mediatorMap.contains(mediator->getMediatorName())) return;

    mediator->initializeNotifier(_multitonKey);

    _mediatorMap[mediator->getMediatorName()] = mediator;

    auto interests = mediator->listNotificationInterests();

    std::function<void(Notification *)> handler = [mediator](Notification *notification) {
        mediator->handleNotification(notification);
    };
    if (!interests.empty()) {
        auto *observer = new Observer(handler, mediator);

        for (auto &interest: interests) {
            registerObserver(interest, observer);
        }
    }

    mediator->onRegister();
}

Mediator *View::retrieveMediator(const std::string &mediatorName) {
    auto position = _mediatorMap.find(mediatorName);
    return position == _mediatorMap.end() ? nullptr : position->second;
}

Mediator *View::removeMediator(const std::string &mediatorName) {
    auto *mediator = _mediatorMap[mediatorName];
    if (mediator) {
        auto interests = mediator->listNotificationInterests();
        for (auto &interest: interests) {
            removeObserver(interest, mediator);
        }
        _mediatorMap.erase(_mediatorMap.find(mediatorName));
        mediator->onRemove();
    }
    return mediator;
}

bool View::hasMediator(const std::string &mediatorName) {
    return _mediatorMap.contains(mediatorName);
}

void View::removeView(const std::string &key) {
    _instanceMap.erase(_instanceMap.find(key));
}

View::~View() = default;
