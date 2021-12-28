#include "ObserverTest.hpp"
#include "Interfaces/Observer.hpp"
#include <iostream>

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Observer::Notification;
using PureMVC::Patterns::Observer::Observer;

struct ViewTestObject {
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

    std::function<void(Notification *)> func = [mediator](Notification *note) { mediator->handleNotification(note); };
    observer->setNotifyMethod(func);

    observer->setNotifyContext(&mediator);

    auto object = ViewTestObject{5};
    auto *notification = new Notification("ObserverTestNote", &object);
    observer->notifyObserver(notification);

    assert(object.value == 10);

    delete notification;
    delete observer;
}

void testObserverConstructor() {
    auto object = ViewTestObject{5};
    auto *mediator = new TestMediator();

    std::function<void(Notification *)> handler = [mediator](Notification *note) {
        mediator->handleNotification(note);
    };
    auto *observer = new Observer(handler, &object);
    auto *notification = new Notification("ObserverTestNote", &object);

    observer->notifyObserver(notification);

    assert(object.value == 10);
    assert(observer->getNotifyMethod());
    assert(observer->getNotifyContext() == &object);

    delete notification;
    delete observer;
}

void testCompareNotifyContext() {
    auto object = ViewTestObject{}, negTestObj = ViewTestObject{};

    auto *observer = new Observer(nullptr, &object);

    assert(observer->compareNotifyContext(&negTestObj) == false);
    assert(observer->compareNotifyContext(&object) == true);

    delete observer;
}

