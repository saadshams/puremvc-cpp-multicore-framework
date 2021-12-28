#ifndef PUREMVC_VIEWTESTMEDIATOR6_HPP
#define PUREMVC_VIEWTESTMEDIATOR6_HPP

#include "Interfaces/Mediator.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;

class ViewTestMediator6 : public Mediator {
public:
    explicit ViewTestMediator6(const std::string &name, const ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    void onRemove() override;

    static constexpr const char* NOTE6 = "Notification6";

    static constexpr const char *NAME = "ViewTestMediator6";
};

#endif //PUREMVC_VIEWTESTMEDIATOR6_HPP
