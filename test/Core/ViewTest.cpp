#include "ViewTest.hpp"

#include <iostream>
#include "Interfaces/View.hpp"
#include "ViewTestMediator.hpp"
#include "ViewTestMediator2.hpp"
#include "ViewTestMediator4.hpp"
#include "ViewTestObject.hpp"

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
    std::cout << "View Tests Passed";
    return 0;
}

void testGetInstance() {
    auto *view = View::getInstance("ViewTestKey1", [](const std::string &k) { return new View(k); });

    assert(view != nullptr);

    View::removeView("ViewTestKey1");
    delete view;
}

void testRegisterAndNotifyObserver() {
    auto *view = View::getInstance("ViewTestKey2", [](const std::string &k) { return new View(k); });

    auto viewTestObject = ViewTestObject{5};
    auto *testMediator = new ViewTestMediator(&viewTestObject);

    std::function<void(Notification*)> handler = [testMediator](Notification *note) {
        testMediator->handleNotification(note);
    };
    auto *observer = new Observer(handler, testMediator);
    view->registerObserver("", observer);

    auto object = ViewTestObject{5};
    auto *notification = new Notification("", &object);
    view->notifyObservers(notification);

    assert(testMediator->getViewTestObject()->value == 10);
}

void testRegisterAndRetrieveMediator() {
    auto *view = View::getInstance("ViewTestKey3", [](const std::string &k){ return new View(k); });

    auto object = ViewTestObject{5};
    auto *viewTestMediator = new ViewTestMediator(&object);
    view->registerMediator(viewTestMediator);
    
    auto *mediator = view->retrieveMediator(ViewTestMediator::NAME);
    
    assert(viewTestMediator == mediator);
}

void testHasMediator() {
    auto *view = View::getInstance("ViewTestKey4", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new Mediator("hasMediatorTest", &object);
    view->registerMediator(mediator);

    assert(view->hasMediator("hasMediatorTest"));

    view->removeMediator("hasMediatorTest");

    assert(!view->hasMediator("hasMediatorTest"));
}

void testRegisterAndRemoveMediator() {
    auto *view = View::getInstance("ViewTestKey5", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new Mediator("testing", &object);
    view->registerMediator(mediator);

    auto removedMediator = view->removeMediator("testing");

    assert(removedMediator->getMediatorName() == "testing");

    assert(view->retrieveMediator("testing") == nullptr);
}

void testOnRegisterAndOnRemove() {
    auto *view = View::getInstance("ViewTestKey6", [](const std::string &k) { return new View(k); });

    auto object = ViewTestObject{5};
    auto *mediator = new ViewTestMediator4(&object);
    view->registerMediator(mediator);

    assert(object.onRegisterCalled);

    view->removeMediator(ViewTestMediator4::NAME);

    assert(object.onRemoveCalled);
}

void testSuccessiveRegisterAndRemoveMediator() {
    auto *view = View::getInstance("ViewTestKey7", [](const std::string &k) {return new View(k); });

    auto object = ViewTestObject{};

    view->registerMediator(new ViewTestMediator(&object));

    assert(dynamic_cast<ViewTestMediator*>(view->retrieveMediator(ViewTestMediator::NAME)) != nullptr);

    view->removeMediator(ViewTestMediator::NAME);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);

    view->registerMediator(new ViewTestMediator(&object));

    assert(dynamic_cast<ViewTestMediator*>(view->retrieveMediator(ViewTestMediator::NAME)) != nullptr);

    view->removeMediator(ViewTestMediator::NAME);

    assert(view->retrieveMediator(ViewTestMediator::NAME) == nullptr);
}

void testRemoveMediatorAndSubsequentNotify() {
    auto *view = View::getInstance("ViewTestKey8", [](const std::string &k){return new View(k);});

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
