#include "ObserverTest.hpp"
#include "Interfaces/Observer.hpp"
#include <iostream>

using PureMVC::Patterns::Observer::Observer;
using PureMVC::Patterns::Observer::Notification;

int value = 5;

static void handleNotification(Notification *notification) {
    *(int *)notification->getBody() = 10;
}

int main() {
    testObserverAccessors();
    testObserverConstructor();
    testCompareNotifyContext();
    std::cout << "Observer Tests Passed";
    return 0;
}

void testObserverAccessors() {
    struct Object {} object;
    auto *observer = new Observer(nullptr, nullptr);
    observer->setNotifyMethod(handleNotification);
    observer->setNotifyContext(&object);

    auto *notification = new Notification("ObserverTestNote", &value);
    observer->notifyObserver(notification);

    assert(value == 10);
    value = 5;

    delete notification;
    delete observer;
}

void testObserverConstructor() {
    struct Object {} object;
    auto *observer = new Observer(handleNotification, &object);
    auto *notification = new Notification("ObserverTestNote", &value);

    observer->notifyObserver(notification);

    assert(value == 10);
    value = 5;

    assert(observer->getNotifyMethod() == handleNotification);
    assert(observer->getNotifyContext() == &object);

    delete notification;
    delete observer;
}

void testCompareNotifyContext() {
    struct Object {} object, negTestObj;
    auto *observer = new Observer(handleNotification, &object);

    assert(observer->compareNotifyContext(&negTestObj) == false);
    assert(observer->compareNotifyContext(&object) == true);

    delete observer;
}
