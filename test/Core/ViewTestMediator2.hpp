#ifndef PUREMVC_VIEWTESTMEDIATOR2_HPP
#define PUREMVC_VIEWTESTMEDIATOR2_HPP

#include "Interfaces/Mediator.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;

class ViewTestMediator2 : public Mediator {
public:
    explicit ViewTestMediator2(ViewTestObject *object);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    static constexpr const char *NOTE1 = "note1";

    static constexpr const char *NOTE2 = "note2";

    static constexpr const char *NAME = "ViewTestMediator2";
};

#endif //PUREMVC_VIEWTESTMEDIATOR2_HPP
