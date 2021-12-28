#include "ViewTest.hpp"
#include "Interfaces/View.hpp"
#include "ViewTestMediator.hpp"
#include "ViewTestMediator2.hpp"
#include "ViewTestMediator3.hpp"
#include "ViewTestMediator4.hpp"
#include "ViewTestMediator5.hpp"
#include "ViewTestMediator6.hpp"
#include "ViewTestObject.hpp"
#include <iostream>

using PureMVC::Core::View;

int main() {
    testGetInstance();
    testRegisterAndNotifyObserver();
    testRegisterAndRetrieveMediator();
    testHasMediator();
    testRegisterAndRemoveMediator();
    testOnRegisterAndOnRemove();
    testSuccessiveRegisterAndRemoveMediator();
    testRemoveMediatorAndSubsequentNotify();
    testRemoveOneOfTwoMediatorsAndSubsequentNotify();
    testMediatorReregistration();
    testModifyObserverListDuringNotification();
    std::cout << "View Tests Passed";
    return 0;
}

void testGetInstance() {
    auto *view = View::getInstance("ViewTestKey1", [](const std::string &k) { return new View(k); });

    assert(view != nullptr);

    View::removeView("ViewTestKey1");
}

void testRegisterAndNotifyObserver() {
    auto *view = View::getInstance("ViewTestKey2", [](const std::string &k) { return new View(k); });

    auto viewTestObject = ViewTestObject{5};
    auto *testMediator = new ViewTestMediator(&viewTestObject);

    auto *observer = new Observer([testMediator](Notification *note) {
        testMediator->handleNotification(note);
    }, testMediator);
    view->registerObserver("ViewTestNote", observer);

    auto object = ViewTestObject{5};
    auto *notification = new Notification("ViewTestNote", &object);
    view->notifyObservers(notification);

    assert(testMediator->getViewTestObject()->value == 10);

    delete testMediator;
    delete observer;
    delete notification;
}

void testRegisterAndRetrieveMediator() {
    auto *view = View::getInstance("ViewTestKey3", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *viewTestMediator = new ViewTestMediator(&object);
    view->registerMediator(viewTestMediator);

    auto *mediator = view->retrieveMediator(ViewTestMediator::NAME);

    assert(viewTestMediator == mediator);

    delete viewTestMediator;
}

void testHasMediator() {
    auto *view = View::getInstance("ViewTestKey4", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new Mediator("hasMediatorTest", &object);
    view->registerMediator(mediator);

    assert(view->hasMediator("hasMediatorTest"));

    view->removeMediator("hasMediatorTest");

    assert(!view->hasMediator("hasMediatorTest"));

    delete mediator;
}

void testRegisterAndRemoveMediator() {
    auto *view = View::getInstance("ViewTestKey5", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new Mediator("testing", &object);
    view->registerMediator(mediator);

    auto removedMediator = view->removeMediator("testing");

    assert(removedMediator->getMediatorName() == "testing");

    assert(view->retrieveMediator("testing") == nullptr);

    delete mediator;
}

void testOnRegisterAndOnRemove() {
    auto *view = View::getInstance("ViewTestKey6", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new ViewTestMediator4(&object);
    view->registerMediator(mediator);

    assert(object.onRegisterCalled);

    view->removeMediator(ViewTestMediator4::NAME);

    assert(object.onRemoveCalled);

    delete mediator;
}

void testSuccessiveRegisterAndRemoveMediator() {
    auto *view = View::getInstance("ViewTestKey7", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{};

    auto *viewTestMediator = new ViewTestMediator(&object);
    view->registerMediator(viewTestMediator);

    assert(dynamic_cast<ViewTestMediator *>(view->retrieveMediator(ViewTestMediator::NAME)) != nullptr);

    view->removeMediator(ViewTestMediator::NAME);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);

    view->registerMediator(viewTestMediator);

    assert(dynamic_cast<ViewTestMediator *>(view->retrieveMediator(ViewTestMediator::NAME)) != nullptr);

    view->removeMediator(ViewTestMediator::NAME);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);

    delete viewTestMediator;
}

void testRemoveMediatorAndSubsequentNotify() {
    auto *view = View::getInstance("ViewTestKey8", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{};
    view->registerMediator(new ViewTestMediator2(&object));

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE1));
    assert(object.lastNotification == ViewTestMediator2::NOTE1);

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE2));
    assert(object.lastNotification == ViewTestMediator2::NOTE2);

    view->removeMediator(ViewTestMediator2::NAME);

    assert(view->retrieveMediator(ViewTestMediator2::NAME) == nullptr);

    object.lastNotification = "";

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE1));

    assert(object.lastNotification != ViewTestMediator2::NOTE1);

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE2));

    assert(object.lastNotification != ViewTestMediator2::NOTE2);
}

void testRemoveOneOfTwoMediatorsAndSubsequentNotify() {
    auto *view = View::getInstance("ViewTestKey9", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{};
    view->registerMediator(new ViewTestMediator2(&object));

    view->registerMediator(new ViewTestMediator3(&object));

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE1));
    assert(object.lastNotification == ViewTestMediator2::NOTE1);

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE2));
    assert(object.lastNotification == ViewTestMediator2::NOTE2);

    view->notifyObservers(new Notification(ViewTestMediator3::NOTE3));

    view->removeMediator(ViewTestMediator2::NAME);

    assert(view->retrieveMediator(ViewTestMediator2::NAME) == nullptr);

    object.lastNotification = "";

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE1));
    assert(object.lastNotification != ViewTestMediator2::NOTE1);

    view->notifyObservers(new Notification(ViewTestMediator2::NOTE2));
    assert(object.lastNotification != ViewTestMediator2::NOTE2);

    view->notifyObservers(new Notification(ViewTestMediator3::NOTE3));
    assert(object.lastNotification == ViewTestMediator3::NOTE3);
}

void testMediatorReregistration() {
    auto *view = View::getInstance("ViewTestKey10", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{};
    view->registerMediator(new ViewTestMediator5(&object));

    view->registerMediator(new ViewTestMediator5(&object));

    object.counter = 0;
    view->notifyObservers(new Notification(ViewTestMediator5::NOTE5));
    assert(object.counter == 1);

    view->removeMediator(ViewTestMediator5::NAME);
    assert(view->retrieveMediator(ViewTestMediator5::NAME) == nullptr);

    object.counter = 0;
    view->notifyObservers(new Notification(ViewTestMediator5::NOTE5));
    assert(object.counter == 0);
}

void testModifyObserverListDuringNotification() {
    auto *view = View::getInstance("ViewTestKey11", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{};

    view->registerMediator(new ViewTestMediator6("ViewTestMediator/1", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/2", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/3", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/4", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/5", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/6", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/7", &object));
    view->registerMediator(new ViewTestMediator6("ViewTestMediator/8", &object));

    object.counter = 0;
    view->notifyObservers(new Notification(ViewTestMediator6::NOTE6));
    assert(object.counter == 8);

    object.counter = 0;
    view->notifyObservers(new Notification(ViewTestMediator6::NOTE6));
    assert(object.counter == 0);
}
