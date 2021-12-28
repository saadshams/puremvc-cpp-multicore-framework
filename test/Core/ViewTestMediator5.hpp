#ifndef PUREMVC_VIEWTESTMEDIATOR5_HPP
#define PUREMVC_VIEWTESTMEDIATOR5_HPP

#include "Interfaces/Mediator.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;

class ViewTestMediator5 : public Mediator {
public:
    explicit ViewTestMediator5(const ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    static constexpr const char* NOTE5 = "Notification5";

    static constexpr const char *NAME = "ViewTestMediator5";
};

#endif //PUREMVC_VIEWTESTMEDIATOR5_HPP
