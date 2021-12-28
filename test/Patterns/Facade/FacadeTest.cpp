#include "Interfaces/Facade.hpp"
#include "Interfaces/Proxy.hpp"
#include "FacadeTest.hpp"
#include "FacadeTestCommand.hpp"
#include "FacadeTestVO.hpp"
#include <iostream>

using PureMVC::Patterns::Facade;

int main() {
    testGetInstance();
    testRegisterCommandAndSendNotification();
    testRegisterAndRemoveCommandAndSendNotification();
    testRegisterAndRetrieveProxy();
    testRegisterAndRemoveProxy();
    testRegisterRetrieveAndRemoveMediator();
    testHasProxy();
    testHasMediator();
    testHasCommand();
    testHasCoreAndRemoveCore();
    std::cout << "Facade Tests Passed";
    return 0;
}

void testGetInstance() {
    auto *facade = Facade::getInstance("FacadeTestKey1", [](const std::string &k) { return new Facade(k); });

    assert(facade != nullptr);
}

void testRegisterCommandAndSendNotification() {
    auto *facade = Facade::getInstance("FacadeTestKey2", [](const std::string &k) { return new Facade(k); });

    facade->registerCommand("FacadeTestNote", []() {return new FacadeTestCommand();});

    auto vo = FacadeTestVO{32};
    facade->sendNotification("FacadeTestNote", &vo);

    assert(vo.result == 64);
}

void testRegisterAndRemoveCommandAndSendNotification() {
    auto *facade = Facade::getInstance("FacadeTestKey3", [](const std::string &k){return new Facade(k);});
    facade->registerCommand("FacadeTestNote", [](){return new FacadeTestCommand();});
    facade->removeCommand("FacadeTestNote");

    auto vo = FacadeTestVO{32};
    facade->sendNotification("FacadeTestNote", &vo);

    assert(vo.result != 64);
}

void testRegisterAndRetrieveProxy() {
    auto *facade = Facade::getInstance("FacadeTestKey4", [](const std::string &k) {return new Facade(k);});
    facade->registerProxy(new Proxy("colors", new std::string[3]{"red", "green", "blue"}));
    auto *proxy = facade->retrieveProxy("colors");

    assert(dynamic_cast<Proxy *>(proxy) != nullptr);

    auto *data = (std::string *)proxy->getData();
    assert(data != nullptr);
    assert(data->size() == 3);
    assert(data[0] == "red");
    assert(data[1] == "green");
    assert(data[2] == "blue");
}

void testRegisterAndRemoveProxy() {
    auto *facade = Facade::getInstance("FacadeTestKey5", [](const std::string &k) {return new Facade(k);});
    facade->registerProxy(new Proxy("sizes", new std::string[]{"7", "13", "21"}));

    auto removedProxy = facade->removeProxy("sizes");

    assert(removedProxy->getProxyName() == "sizes");

    assert(facade->retrieveProxy("sizes") == nullptr);
}

void testRegisterRetrieveAndRemoveMediator() {
    auto *facade = Facade::getInstance("FacadeTestKey6", [](const std::string &k) {return new Facade(k);});
    auto vo = FacadeTestVO{};
    facade->registerMediator(new Mediator(Mediator::NAME, &vo));

    assert(facade->retrieveMediator(Mediator::NAME) != nullptr);

    auto *removedMediator = facade->removeMediator(Mediator::NAME);

    assert(removedMediator->getMediatorName() == Mediator::NAME);

    assert(facade->retrieveMediator(Mediator::NAME) == nullptr);
}

void testHasProxy() {
    auto *facade = Facade::getInstance("FacadeTestKey7", [](const std::string &k) {return new Facade(k);});
    facade->registerProxy(new Proxy("hasProxyTest", new int[]{1, 2, 3}));

    assert(facade->hasProxy("hasProxyTest") == true);
}

void testHasMediator() {
    auto *facade = Facade::getInstance("FacadeTestKey8", [](const std::string &k){return new Facade(k);});
    auto vo = FacadeTestVO{};
    facade->registerMediator(new Mediator("facadeHasMediatorTest", &vo));

    assert(facade->hasMediator("facadeHasMediatorTest"));

    facade->removeMediator("facadeHasMediatorTest");

    assert(facade->hasMediator("facadeHasMediatorTest") == false);
}

void testHasCommand() {
    auto *facade = Facade::getInstance("FacadeTestKey10", [](const std::string &k){return new Facade(k);});
    facade->registerCommand("facadeHasCommandTest", [](){return new FacadeTestCommand();});

    assert(facade->hasCommand("facadeHasCommandTest"));

    facade->removeCommand("facadeHasCommandTest");

    assert(facade->hasCommand("facadeHasCommandTest") == false);
}

void testHasCoreAndRemoveCore() {
    assert(Facade::hasCore("FacadeTestKey11") == false);
    auto *facade = Facade::getInstance("FacadeTestKey11", [](const std::string &k){return new Facade(k);});

    assert(Facade::hasCore("FacadeTestKey11") == true);

    Facade::removeCore("FacadeTestKey11");

    assert(Facade::hasCore("FacadeTestKey11") == false);
}
