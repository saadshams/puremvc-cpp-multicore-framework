#ifndef PUREMVC_NOTIFICATION_HPP
#define PUREMVC_NOTIFICATION_HPP

#include <iostream>

namespace PureMVC::Patterns::Observer {
    class Notification {
    protected:
        std::string _name;
        void const* _body;
        std::string _type;
    public:
        explicit Notification(std::string const& name, void const*body = nullptr, std::string const&type = "");

        virtual std::string const& getName() const;

        virtual void setBody(void const* body);

        virtual void const* getBody() const;

        virtual void setType(std::string const& type);

        virtual std::string const& getType() const;

        virtual std::string toString() const;

        virtual ~Notification();
    };
}

#endif //PUREMVC_NOTIFICATION_HPP
