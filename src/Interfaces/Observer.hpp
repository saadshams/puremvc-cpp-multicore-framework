#ifndef PUREMVC_OBSERVER_HPP
#define PUREMVC_OBSERVER_HPP

#include "Mediator.hpp"
#include "Notification.hpp"

namespace PureMVC::Patterns::Observer {
    class Observer {
    protected:
        std::function<void(Notification *)> _notify;
        const void *_context;
    public:
        explicit Observer(std::function<void(Notification *)> notify, const void *context);

        virtual void notifyObserver(Notification *notification);

        virtual bool compareNotifyContext(const void *object) const;

        virtual void setNotifyContext(const void *context);

        virtual void setNotifyMethod(std::function<void(Notification *)> notify);

        [[nodiscard]] virtual const void *getNotifyContext() const;

        [[nodiscard]] virtual std::function<void(Notification *)> getNotifyMethod();

        virtual ~Observer();
    };
}

#endif //PUREMVC_OBSERVER_HPP
