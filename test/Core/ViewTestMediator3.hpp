#ifndef PUREMVC_VIEWTESTMEDIATOR3_HPP
#define PUREMVC_VIEWTESTMEDIATOR3_HPP

#include "Interfaces/Mediator.hpp"
#include "Interfaces/Notification.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Notification;

class ViewTestMediator3 : public Mediator {
public:
    explicit ViewTestMediator3(const ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    static constexpr const char *NOTE3 = "Notification3";

    static constexpr const char *NAME = "ViewTestMediator3";
};

#endif //PUREMVC_VIEWTESTMEDIATOR3_HPP
