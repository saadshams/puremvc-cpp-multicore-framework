#ifndef PUREMVC_VIEWTESTMEDIATOR_HPP
#define PUREMVC_VIEWTESTMEDIATOR_HPP

#import "Interfaces/Mediator.hpp"
#import "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;

class ViewTestMediator : public Mediator {
public:
    explicit ViewTestMediator(const ViewTestObject *ViewTestObject);

    std::vector<std::string> listNotificationInterests() override;

    void handleNotification(Notification *notification) override;

    [[nodiscard]] const ViewTestObject * getViewTestObject() const;

    static constexpr const char *NAME = "ViewTestMediator";
};

#endif //PUREMVC_VIEWTESTMEDIATOR_HPP
