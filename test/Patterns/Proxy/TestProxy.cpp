#include "TestProxy.h"
#include "Interfaces/Proxy.h"
#include <iostream>
#include <cassert>

using PureMVC::Patterns::Proxy;
using std::string;

int main() {
    testNameAccessor();
    testDataAccessors();
    testConstructor();
    return 0;
}

void testNameAccessor() {
    Proxy proxy = Proxy("TestProxy");
    assert(proxy.proxyName() == "TestProxy");
    proxy.onRegister();
    proxy.onRemove()
}

void testDataAccessors() {
    Proxy proxy = Proxy("colors", nullptr);

    proxy.setData(new string[3]{"red", "green", "blue"});

    auto* colors = (string *) proxy.getData();

    assert(colors[0] == "red");
    assert(colors[1] == "green");
    assert(colors[2] == "blue");
}

void testConstructor() {
    Proxy proxy = Proxy("colors", new string[3]{"red", "green", "blue"});

    auto* colors = (string *) proxy.getData();
    assert(colors[0] == "red");
    assert(colors[1] == "green");
    assert(colors[2] == "blue");
}
