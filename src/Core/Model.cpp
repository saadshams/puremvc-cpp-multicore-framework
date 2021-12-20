#include "Interfaces/Model.hpp"

using PureMVC::Core::Model;

Model::Model(const std::string &key) {
    if (_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
}

Model *Model::getInstance(const std::string &key) {
    if (!_instanceMap.contains(key)) _instanceMap[key] = new Model(key);
    _instanceMap[key]->initializeModel();
    return Model::_instanceMap[key];
}

void Model::initializeModel() {

}

void Model::registerProxy(Proxy *proxy) {
    proxy->initializeNotifier(_multitonKey);
    _proxyMap[proxy->getProxyName()] = proxy;
    proxy->onRegister();
}

Proxy *Model::retrieveProxy(const std::string &proxyName) {
    return _proxyMap[proxyName];
}

bool Model::hasProxy(const std::string &proxyName) {
    return _proxyMap.contains(proxyName);
}

Proxy *Model::removeProxy(const std::string &proxyName) {
    Proxy *proxy = _proxyMap[proxyName];
    if (proxy != nullptr) {
        _proxyMap.erase(proxyName);
        proxy->onRemove();
    }
    return proxy;
}

Model::~Model() {
    // removeModel(_multitonKey);
    _proxyMap.clear();
}
