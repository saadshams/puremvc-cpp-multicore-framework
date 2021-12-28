#ifndef PUREMVC_NOTIFICATION_HPP
#define PUREMVC_NOTIFICATION_HPP

#include <iostream>

namespace PureMVC::Patterns {
    class Notification {
    protected:
        std::string _name;
        const void *_body;
        std::string _type;
    public:
        explicit Notification(const std::string &name, const void *body = nullptr, const std::string &type = "");

        [[nodiscard]] virtual const std::string &getName() const;

        virtual void setBody(const void *body);

        [[nodiscard]] virtual const void *getBody() const;

        virtual void setType(const std::string &type);

        [[nodiscard]] virtual const std::string &getType() const;

        [[nodiscard]] virtual std::string toString() const;

        virtual ~Notification();
    };
}

#endif //PUREMVC_NOTIFICATION_HPP
