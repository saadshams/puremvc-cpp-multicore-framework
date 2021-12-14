#include "ProxyTest.hpp"
#include "Interfaces/Proxy.hpp"
#include <iostream>
#include <cassert>

using PureMVC::Patterns::Proxy;

int main() {
    testNameAccessor();
    testDataAccessors();
    testConstructor();
    std::cout << "Proxy Tests Passed";
    return 0;
}

void testNameAccessor() {
    Proxy *proxy = new Proxy("TestProxy");
    assert(proxy->getProxyName() == "TestProxy");
    proxy->onRegister();
    proxy->onRemove();

    delete proxy;
}

void testDataAccessors() {
    Proxy *proxy = new Proxy("colors", nullptr);

    proxy->setData(new std::string[3]{"red", "green", "blue"});

    auto* colors = (std::string *) proxy->getData();

    assert(colors[0] == "red");
    assert(colors[1] == "green");
    assert(colors[2] == "blue");

    delete proxy;
}

void testConstructor() {
    Proxy *proxy = new Proxy("colors", new std::string[3]{"red", "green", "blue"});

    auto* colors = (std::string *) proxy->getData();
    assert(colors[0] == "red");
    assert(colors[1] == "green");
    assert(colors[2] == "blue");

    delete proxy;
}
