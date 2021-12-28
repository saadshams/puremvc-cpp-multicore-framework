#include "Interfaces/Proxy.hpp"

using PureMVC::Patterns::Proxy;

Proxy::Proxy(const std::string &proxyName, const void *data) {
    this->_proxyName = proxyName;
    this->_data = data;
}

void Proxy::onRegister() {

}

void Proxy::onRemove() {

}

const std::string &Proxy::getProxyName() const {
    return this->_proxyName;
}

void Proxy::setData(const void *data) {
    this->_data = data;
}

const void *Proxy::getData() const {
    return this->_data;
}

Proxy::~Proxy() = default;
