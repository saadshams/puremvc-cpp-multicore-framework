#ifndef PUREMVC_OBSERVER_HPP
#define PUREMVC_OBSERVER_HPP

#include "Notification.hpp"

namespace PureMVC::Patterns::Observer {
    class Observer {
    protected:
        void (*_notify)(Notification *notification);
        void const* _context;
    public:
        Observer(void (*notify)(Notification *notification), const void *context);

        void notifyObserver(Notification *notification);

        bool compareNotifyContext(void const* object);

        void setNotifyContext(void const* context);

        void setNotifyMethod(void (*notify)(Notification *notification));

        [[nodiscard]] void const* getNotifyContext() const;

        [[nodiscard]] void (*getNotifyMethod() const)(Notification *note);

        virtual ~Observer();
    };
}

#endif //PUREMVC_OBSERVER_HPP
