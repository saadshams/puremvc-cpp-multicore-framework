#ifndef PUREMVC_MEDIATOR_HPP
#define PUREMVC_MEDIATOR_HPP

#include <iostream>
#include <vector>
#include "Notification.hpp"
#include "Notifier.hpp"

namespace PureMVC::Patterns {
    class Mediator : public Notifier {
    protected:
        std::string _mediatorName;
        const void *_viewComponent;
    public:
        explicit Mediator(const std::string &mediatorName = NAME, const void *viewComponent = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        virtual std::vector<std::string> listNotificationInterests();

        virtual void handleNotification(Notification *notification);

        [[nodiscard]] virtual const std::string &getMediatorName() const;

        virtual void setViewComponent(const void *viewComponent);

        [[nodiscard]] virtual const void *getViewComponent() const;

        ~Mediator() override;

        static constexpr const char *NAME = "Mediator";
    };
}

#endif //PUREMVC_MEDIATOR_HPP
