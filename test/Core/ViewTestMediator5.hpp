#ifndef PUREMVC_VIEWTESTMEDIATOR5_HPP
#define PUREMVC_VIEWTESTMEDIATOR5_HPP

#include "Interfaces/Mediator.hpp"
#include "Interfaces/Notification.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Notification;

class ViewTestMediator5 : public Mediator {
public:
    explicit ViewTestMediator5(const ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    static constexpr const char* NOTE5 = "Notification5";

    static constexpr const char *NAME = "ViewTestMediator5";
};

#endif //PUREMVC_VIEWTESTMEDIATOR5_HPP
