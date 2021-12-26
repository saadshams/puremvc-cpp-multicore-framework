#include "ObserverTest.hpp"
#include "Interfaces/Observer.hpp"
#include <iostream>

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Observer::Notification;
using PureMVC::Patterns::Observer::Observer;

struct Object {
    int value;
};

class TestMediator : Mediator {
public:
    void handleNotification(Notification *notification) override {
        *(int *) notification->getBody() = 10;
    }
};

int main() {
    testObserverAccessors();
    testObserverConstructor();
    testCompareNotifyContext();
    std::cout << "Observer Tests Passed";
    return 0;
}

void testObserverAccessors() {
    auto *mediator = new TestMediator();
    auto *observer = new Observer(nullptr, nullptr);

    observer->setNotifyMethod([mediator](Notification* note){mediator->handleNotification(note);});
    observer->setNotifyContext(&mediator);

    auto object = Object{5};
    auto *notification = new Notification("ObserverTestNote", &object);
    observer->notifyObserver(notification);

    assert(object.value == 10);

    delete notification;
    delete observer;
}

void testObserverConstructor() {
    auto object = Object{5};
    auto *mediator = new TestMediator();

    auto *observer = new Observer([mediator](Notification *note) { mediator->handleNotification(note); }, &object);
    auto *notification = new Notification("ObserverTestNote", &object);

    observer->notifyObserver(notification);

    assert(object.value == 10);
    assert(observer->getNotifyMethod());
    assert(observer->getNotifyContext() == &object);

    delete notification;
    delete observer;
}

void testCompareNotifyContext() {
    auto object = Object{}, negTestObj = Object{};

    auto *observer = new Observer(nullptr, &object);

    assert(observer->compareNotifyContext(&negTestObj) == false);
    assert(observer->compareNotifyContext(&object) == true);

    delete observer;
}
