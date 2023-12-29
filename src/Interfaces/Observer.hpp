#ifndef PUREMVC_OBSERVER_HPP
#define PUREMVC_OBSERVER_HPP

#include "Notification.hpp"

namespace PureMVC::Patterns {
    class Observer {
    protected:
        std::function<void(Notification * notification)> notify;
        const void *context;
    public:
        explicit Observer(std::function<void(Notification * )> notify = nullptr, const void *context = nullptr);

        virtual void notifyObserver(Notification *notification);

        virtual bool compareNotifyContext(const void *object) const;

        virtual void setNotifyContext(const void *context);

        virtual void setNotifyMethod(std::function<void(Notification * )> notify);

        virtual const void *getNotifyContext() const;

        virtual std::function<void(Notification * )> getNotifyMethod();

        virtual ~Observer();
    };
}

#endif //PUREMVC_OBSERVER_HPP
