#include <iostream>
#include "ModelTest.hpp"
#include "Interfaces/Model.hpp"
#include "ModelTestProxy.hpp"

using PureMVC::Core::Model;

int main() {
    testGetInstance();
    testRegisterAndRetrieveProxy();
    testRegisterAndRemoveProxy();
    testHasProxy();
    testOnRegisterAndOnRemove();
    std::cout << "Model Tests Passed";
    return 0;
}

void testGetInstance() {
    auto *model = Model::getInstance("ModelTestKey1", [](std::string k) { return new Model(k); });

    assert(model != nullptr);
}

void testRegisterAndRetrieveProxy() {
    auto *model = Model::getInstance("ModelTestKey2", [](std::string k) { return new Model(k); });
    model->registerProxy(new Proxy("colors", new std::string[3]{"red", "green", "blue"}));
    auto *proxy = model->retrieveProxy("colors");

    auto *colors = (std::string *) proxy->getData();

    assert(colors[0] == "red");
    assert(colors[1] == "green");
    assert(colors[2] == "blue");

    delete proxy;
}

void testRegisterAndRemoveProxy() {
    auto *model = Model::getInstance("ModelTestKey3", [](std::string k) { return new Model(k); });

    auto *proxy = new Proxy("sizes", new std::string[3]{"7", "13", "21"});
    model->registerProxy(proxy);

    auto *removedProxy = model->removeProxy("sizes");

    assert(removedProxy->getProxyName() == "sizes");

    proxy = model->retrieveProxy("sizes");
    assert(proxy == nullptr);

    delete proxy;
}

void testHasProxy() {
    auto *model = Model::getInstance("ModelTestKey4", [](std::string k) { return new Model(k); });
    auto *proxy = new Proxy("aces", new std::string[4]{"clubs", "spades", "hearts", "diamonds"});
    model->registerProxy(proxy);

    assert(model->hasProxy("aces") == true);

    model->removeProxy("aces");

    assert(model->hasProxy("aces") == false);

    delete proxy;
}

void testOnRegisterAndOnRemove() {
    auto *model = Model::getInstance("ModelTestKey5", [](std::string k) { return new Model(k); });
    Proxy *proxy = new ModelTestProxy();
    model->registerProxy(proxy);

    assert(proxy->getData() == ModelTestProxy::ON_REGISTER_CALLED);

    model->removeProxy(ModelTestProxy::NAME);

    assert(proxy->getData() == ModelTestProxy::ON_REMOVE_CALLED);
}
