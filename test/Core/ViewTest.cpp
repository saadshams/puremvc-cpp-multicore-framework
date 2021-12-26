#include "ViewTest.hpp"

#include <iostream>
#include "Interfaces/View.hpp"

using PureMVC::Core::View;

int main() {
    testGetInstance();
    testRegisterAndNotifyObserver();
    std::cout << "View Tests Passed";
    return 0;
}

struct Object {
    int value;
};

class TestMediator : public Mediator {
public:
    int value = 0;
    void handleNotification(Notification *notification) override {
        value = ((Object *) notification->getBody())->value * 2;
    }
};

void testGetInstance() {
    auto *view = View::getInstance("ViewTestKey1", [](const std::string &k) { return new View(k); });

    assert(view != nullptr);

    View::removeView("ViewTestKey1");
    delete view;
}

void testRegisterAndNotifyObserver() {
    auto *view = View::getInstance("ViewTestKey2", [](const std::string &k) { return new View(k); });

    auto *testMediator = new TestMediator();

    auto *observer = new Observer([testMediator](Notification *note) {
        testMediator->handleNotification(note);
    }, testMediator);

    view->registerObserver("", observer);

    auto object = Object{5};
    auto *notification = new Notification("", &object);
    view->notifyObservers(notification);

    assert(testMediator->value == 10);
}

