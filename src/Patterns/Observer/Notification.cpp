#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::Observer::Notification;

Notification::Notification(const std::string &name, const void *body, const std::string &type) {
    this->_name = name;
    this->_body = body;
    this->_type = type;
}

std::string const &Notification::getName() const {
    return this->_name;
}

void Notification::setBody(const void *body) {
    this->_body = body;
}

void const *Notification::getBody() const {
    return this->_body;
}

void Notification::setType(std::string const &type) {
    this->_type = type;
}

std::string const &Notification::getType() const {
    return this->_type;
}

std::string Notification::toString() const {
    std::string msg = "Notification Name: ";
    msg += this->_name;
    msg += "\nBody: ";
    msg += typeid(this->_body).name();
    msg += "\nType: ";
    msg += this->_type;
    return msg;
}

Notification::~Notification() = default;
