#include "Interfaces/View.hpp"

using PureMVC::Core::View;

View::View(const std::string &key) {
    if (instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    multitonKey = key;
    instanceMap[key] = this;
}

View *View::getInstance(const std::string &key, const std::function<View *(const std::string &k)> &factory) {
    if (!instanceMap.contains(key)) {
        instanceMap[key] = factory(key);
        instanceMap[key]->initializeView();
    }
    return instanceMap[key];
}

void View::initializeView() {

}

void View::registerObserver(const std::string &notificationName, Observer *observer) {
    observerMap[notificationName].push_back(observer);
}

void View::notifyObservers(Notification *notification) {
    if (observerMap.contains(notification->getName())) {
        auto observers = observerMap[notification->getName()];

        std::for_each(observers.begin(), observers.end(), [notification](auto *observer) {
            observer->notifyObserver(notification);
        });
    }
}

void View::removeObserver(const std::string &notificationName, const void *notifyContext) {
    auto observers = observerMap[notificationName];

    for (unsigned int i = 0; i < observers.size(); i++) {
        if (observers[i]->compareNotifyContext(notifyContext)) {
            observers.erase(observers.begin() + i);
            break;
        }
    }

    if (observers.empty()) {
        observerMap.erase(observerMap.find(notificationName));
    }
}

void View::registerMediator(Mediator *mediator) {
    if (mediatorMap.contains(mediator->getMediatorName())) return;

    mediator->initializeNotifier(multitonKey);

    mediatorMap[mediator->getMediatorName()] = mediator;

    auto interests = mediator->listNotificationInterests();

    if (!interests.empty()) {
        auto *observer = new Observer([mediator](Notification *notification) {
            mediator->handleNotification(notification);
        }, mediator);

        for (auto &interest: interests) {
            registerObserver(interest, observer);
        }
    }

    mediator->onRegister();
}

Mediator *View::retrieveMediator(const std::string &mediatorName) {
    auto position = mediatorMap.find(mediatorName);
    return position == mediatorMap.end() ? nullptr : position->second;
}

Mediator *View::removeMediator(const std::string &mediatorName) {
    auto *mediator = mediatorMap[mediatorName];
    if (mediator) {
        auto interests = mediator->listNotificationInterests();
        for (auto &interest: interests) {
            removeObserver(interest, mediator);
        }
        mediatorMap.erase(mediatorMap.find(mediatorName));
        mediator->onRemove();
    }
    return mediator;
}

bool View::hasMediator(const std::string &mediatorName) {
    return mediatorMap.contains(mediatorName);
}

void View::removeView(const std::string &key) {
    instanceMap.erase(instanceMap.find(key));
}

View::~View() {
    removeView(multitonKey);
    observerMap.clear();
    mediatorMap.clear();
}
