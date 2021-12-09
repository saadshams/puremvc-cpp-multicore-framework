#include "../../Interfaces/Proxy.h"

using PureMVC::Patterns::Proxy;

Proxy::Proxy(const string& proxyName, const void* data) {
    _proxyName = proxyName;
    _data = data;
}

void Proxy::onRegister() {

}

void Proxy::onRemove() {

}

string Proxy::proxyName() {
    return _proxyName;
}

void Proxy::setData(const void* data) {
    _data = data;
}

void const *Proxy::getData() {
    return _data;
}

Proxy::~Proxy() = default;
