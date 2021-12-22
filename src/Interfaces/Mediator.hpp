#ifndef PUREMVC_MEDIATOR_HPP
#define PUREMVC_MEDIATOR_HPP

#include <iostream>
#include "Interfaces/Notification.hpp"

using PureMVC::Patterns::Observer::Notification;

namespace PureMVC::Patterns {
    class Mediator {
    protected:
        std::string _mediatorName;
        const void *_viewComponent;
    public:
        explicit Mediator(const std::string &mediatorName = NAME, const void *viewComponent = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        virtual const char *const *listNotificationInterests();

        virtual void handleNotification(Notification *notification);

        [[nodiscard]] virtual const std::string &getMediatorName() const;

        virtual void setViewComponent(const void *viewComponent);

        [[nodiscard]] virtual const void *getViewComponent() const;

        virtual ~Mediator();

        static constexpr const char *NAME = "Mediator";
    };
}

#endif //PUREMVC_MEDIATOR_HPP
