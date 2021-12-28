#ifndef PUREMVC_VIEWTESTMEDIATOR2_HPP
#define PUREMVC_VIEWTESTMEDIATOR2_HPP

#include "Interfaces/Mediator.hpp"
#include "Interfaces/Notification.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Notification;

class ViewTestMediator2 : public Mediator {
public:
    explicit ViewTestMediator2(ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    static constexpr const char *NOTE1 = "Notification1";

    static constexpr const char *NOTE2 = "Notification2";

    static constexpr const char *NAME = "ViewTestMediator2";
};

#endif //PUREMVC_VIEWTESTMEDIATOR2_HPP
