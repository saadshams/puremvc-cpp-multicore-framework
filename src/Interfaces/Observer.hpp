#ifndef PUREMVC_OBSERVER_HPP
#define PUREMVC_OBSERVER_HPP

#include "Notification.hpp"

namespace PureMVC::Patterns::Observer {
    class Observer {
    protected:
        void (*_notify)(Notification *notification);

        const void *_context;
    public:
        Observer(void (*notify)(Notification *notification), const void *context);

        virtual void notifyObserver(Notification *notification);

        virtual bool compareNotifyContext(const void *object) const;

        virtual void setNotifyContext(const void *context);

        virtual void setNotifyMethod(void (*notify)(Notification *notification));

        [[nodiscard]] virtual const void *getNotifyContext() const;

        [[nodiscard]] virtual void (*getNotifyMethod())(Notification *notification);

        virtual ~Observer();
    };
}

#endif //PUREMVC_OBSERVER_HPP
