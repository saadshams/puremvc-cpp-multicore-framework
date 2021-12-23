#include <iostream>
#include "ControllerTest.hpp"
#include "ControllerTestCommand.hpp"
#include "ControllerTestCommand2.hpp"
#include "Interfaces/Controller.hpp"
#include "Interfaces/Notification.hpp"
#include "ControllerTestVO.hpp"

using PureMVC::Core::Controller;
using PureMVC::Patterns::Observer::Notification;

int main() {
    testGetInstance();
    testRegisterAndExecuteCommand();
    testRegisterAndRemoveCommand();
    testHasCommand();
    testReregisterAndExecuteCommand();
    std::cout << "Controller Tests Passed";
    return 0;
}

void testGetInstance() {
    auto *controller = Controller::getInstance("ControllerTestKey1",
                                               [](const std::string &k) { return new Controller(k); });

    assert(controller != nullptr);

    Controller::removeController("ControllerTestKey1");
    delete controller;
}

void testRegisterAndExecuteCommand() {
    auto *controller = Controller::getInstance("ControllerTestKey2",
                                               [](const std::string &k) { return new Controller(k); });

    controller->registerCommand("ControllerTest", []() -> SimpleCommand * { return new ControllerTestCommand(); });

    auto vo = ControllerTestVO{12};
    auto *notification = new Notification("ControllerTest", &vo);

    controller->executeCommand(notification);

    assert(vo.result == 24);

    Controller::removeController("");
    delete notification;
    delete controller;
}

void testRegisterAndRemoveCommand() {
    auto *controller = Controller::getInstance("ControllerTestKey3",
                                               [](const std::string &k) { return new Controller(k); });
    controller->registerCommand("ControllerRemoveTest",
                                []() -> SimpleCommand * { return new ControllerTestCommand(); });

    auto vo = ControllerTestVO{12};
    auto notification = new Notification("ControllerRemoveTest", &vo);

    controller->executeCommand(notification);

    assert(vo.result == 24);

    vo.result = 0;

    controller->removeCommand("ControllerRemoveTest");

    controller->executeCommand(notification);

    assert(vo.result == 0);
}

void testHasCommand() {
    auto *controller = Controller::getInstance("ControllerTestKey4",
                                               [](const std::string &k) { return new Controller(k); });
    controller->registerCommand("hasCommandTest", []() -> SimpleCommand * { return new ControllerTestCommand(); });

    assert(controller->hasCommand("hasCommandTest") == true);

    controller->removeCommand("hasCommandTest");

    assert(controller->hasCommand("hasCommandTest") == false);
}

void testReregisterAndExecuteCommand() {
    auto *controller = Controller::getInstance("ControllerTestKey5", [](const std::string &k) { return new Controller(k); });

    controller->registerCommand("ControllerTest2", []() -> SimpleCommand * { return new ControllerTestCommand2(); });

    controller->removeCommand("ControllerTest2");

    controller->registerCommand("ControllerTest2", []() -> SimpleCommand * { return new ControllerTestCommand2(); });

//    auto vo = ControllerTestVO{12};
//    auto *notification = new Notification("ControllerTest2", &vo);

    // auto *view = View::getInstance("ControllerTestKey5", [](const std::string &k) {return new View(k); });

    // view->notifyObserver(notification);

    // assert(vo.result == 24);

    // view.notifyObservers(notification);

    // assert(vo.result == 48);
}
