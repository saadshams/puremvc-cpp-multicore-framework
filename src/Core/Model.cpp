#include "Interfaces/Model.hpp"

using PureMVC::Core::Model;

Model::Model(const std::string &key) {
    if (instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    multitonKey = key;
    instanceMap[key] = this;
}

Model *Model::getInstance(const std::string &key, const std::function<Model *(const std::string &k)> &factory) {
    if (!instanceMap.contains(key)) {
        instanceMap[key] = factory(key);
        instanceMap[key]->initializeModel();
    }
    return instanceMap[key];
}

void Model::initializeModel() {

}

void Model::registerProxy(Proxy *proxy) {
    proxy->initializeNotifier(multitonKey);
    proxyMap[proxy->getProxyName()] = proxy;
    proxy->onRegister();
}

Proxy *Model::retrieveProxy(const std::string &proxyName) {
    return proxyMap[proxyName];
}

bool Model::hasProxy(const std::string &proxyName) {
    return proxyMap.contains(proxyName);
}

Proxy *Model::removeProxy(const std::string &proxyName) {
    Proxy *proxy = proxyMap[proxyName];
    if (proxy != nullptr) {
        proxyMap.erase(proxyName);
        proxy->onRemove();
    }
    return proxy;
}

void Model::removeModel(const std::string &key) {
    instanceMap.erase(instanceMap.find(key));
}

Model::~Model() {
    removeModel(multitonKey);
    proxyMap.clear();
}
