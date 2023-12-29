#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::Notification;

Notification::Notification(const std::string &name, const void *body, const std::string &type) {
    this->name = name;
    this->body = body;
    this->type = type;
}

const std::string &Notification::getName() const {
    return this->name;
}

void Notification::setBody(const void *body) {
    this->body = body;
}

const void *Notification::getBody() const {
    return this->body;
}

void Notification::setType(const std::string &type) {
    this->type = type;
}

const std::string &Notification::getType() const {
    return this->type;
}

std::string Notification::toString() const {
    std::string msg = "Notification Name: ";
    msg += this->name;
    msg += "\nBody: ";
    msg += typeid(this->body).name();
    msg += "\nType: ";
    msg += this->type;
    return msg;
}

Notification::~Notification() = default;
