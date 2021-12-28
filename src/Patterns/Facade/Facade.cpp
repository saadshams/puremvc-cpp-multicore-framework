#include "Interfaces/Facade.hpp"

using PureMVC::Patterns::Facade;

Facade::Facade(const std::string &key) {
    if(_instanceMap.contains(key)) throw std::runtime_error(MULTITON_MSG);
    _multitonKey = key;
    _instanceMap[key] = this;
}

Facade *Facade::getInstance(const std::string &key, const std::function<Facade *(const std::string &)> &factory) {
    if(!_instanceMap.contains(key)) _instanceMap[key] = factory(key);
    _instanceMap[key]->initializeFacade();
    return _instanceMap[key];
}

void Facade::initializeFacade() {
    initializeModel();
    initializeController();
    initializeView();
}

void Facade::initializeModel() {
    _model = Model::getInstance(_multitonKey, [](const std::string &k){return new Model(k);});
}

void Facade::initializeController() {
    _controller = Controller::getInstance(_multitonKey, [](const std::string &k){return new Controller(k); });
}

void Facade::initializeView() {
    _view = View::getInstance(_multitonKey, [](const std::string &k){return new View(k);});
}

void Facade::registerCommand(const std::string &key, const std::function<SimpleCommand *()> &factory) {
    _controller->registerCommand(key, factory);
}

void Facade::removeCommand(const std::string &notificationName) {
    _controller->removeCommand(notificationName);
}

bool Facade::hasCommand(const std::string &notificationName) {
    return _controller->hasCommand(notificationName);
}

void Facade::registerProxy(Proxy *proxy) {
    _model->registerProxy(proxy);
}

Proxy *Facade::retrieveProxy(const std::string &proxyName) {
    return _model->retrieveProxy(proxyName);
}

Proxy *Facade::removeProxy(const std::string &proxyName) {
    return _model->removeProxy(proxyName);
}

bool Facade::hasProxy(const std::string &proxyName) {
    return _model->hasProxy(proxyName);
}

void Facade::registerMediator(Mediator *mediator) {
    _view->registerMediator(mediator);
}

Mediator *Facade::retrieveMediator(const std::string &mediatorName) {
    return _view->retrieveMediator(mediatorName);
}

Mediator *Facade::removeMediator(const std::string &mediatorName) {
    return _view->removeMediator(mediatorName);
}

bool Facade::hasMediator(const std::string &mediatorName) {
    return _view->hasMediator(mediatorName);
}

void Facade::sendNotification(const std::string &name, const void *body, const std::string &type) {
    notifyObservers(new Notification(name, body, type));
}

void Facade::notifyObservers(Notification *notification) {
    _view->notifyObservers(notification);
}

void Facade::initializeNotifier(const std::string &key) {
    _multitonKey = key;
}

bool Facade::hasCore(const std::string &key) {
    return _instanceMap.contains(key);
}

void Facade::removeCore(const std::string &key) {
    Model::removeModel(key);
    View::removeView(key);
    Controller::removeController(key);
    _instanceMap.erase(_instanceMap.find(key));
}
