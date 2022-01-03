#include "TestNotifier.hpp"
#include "Interfaces/Facade.hpp"
#include "Interfaces/Notifier.hpp"
#include "FacadeTestCommand.hpp"
#include "FacadeTestVO.hpp"
#include <iostream>

using PureMVC::Patterns::Notifier;

int main() {
    testRegisterCommandAndSendNotification();
    std::cout << "Notifier Tests Passed";
    return 0;
}

void testRegisterCommandAndSendNotification() {
    auto *notifier = new Notifier();
    notifier->initializeNotifier("NotifierTestKey1");
    auto *facade = notifier->getFacade();

    facade->registerCommand("NotifierTestNote", []() { return new FacadeTestCommand(); });

    auto vo = FacadeTestVO{32};
    notifier->sendNotification("NotifierTestNote", &vo);

    assert(vo.result == 64);

    notifier->sendNotification("unknown");
    notifier->sendNotification("unknown", &vo, "unknownType");
}


