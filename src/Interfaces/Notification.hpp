#ifndef PUREMVC_NOTIFICATION_HPP
#define PUREMVC_NOTIFICATION_HPP

#include <iostream>

namespace PureMVC::Patterns {
    class Notification {
    protected:
        std::string name;
        const void *body;
        std::string type;
    public:
        explicit Notification(const std::string &name, const void *body = nullptr, const std::string &type = "");

        virtual const std::string &getName() const;

        virtual void setBody(const void *body);

        virtual const void *getBody() const;

        virtual void setType(const std::string &type);

        virtual const std::string &getType() const;

        virtual std::string toString() const;

        virtual ~Notification();
    };
}

#endif //PUREMVC_NOTIFICATION_HPP
