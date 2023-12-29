#include "Interfaces/Proxy.hpp"

using PureMVC::Patterns::Proxy;

Proxy::Proxy(const std::string &proxyName, const void *data) {
    this->proxyName = proxyName;
    this->data = data;
}

void Proxy::onRegister() {

}

void Proxy::onRemove() {

}

const std::string &Proxy::getProxyName() const {
    return this->proxyName;
}

void Proxy::setData(const void *data) {
    this->data = data;
}

const void *Proxy::getData() const {
    return this->data;
}

Proxy::~Proxy() = default;
