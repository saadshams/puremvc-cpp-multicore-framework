#include "ViewTestMediator.hpp"

ViewTestMediator::ViewTestMediator(const ViewTestObject *object) : Mediator(NAME, object)  {

}

std::vector<std::string> ViewTestMediator::listNotificationInterests() {
    return {"ABC", "DEF", "GHI"};
}

void ViewTestMediator::handleNotification(Notification *notification) {
    ((ViewTestObject *) _viewComponent)->value = ((ViewTestObject *) notification->getBody())->value * 2;
}

const ViewTestObject *ViewTestMediator::getViewTestObject() const {
    return (ViewTestObject *)_viewComponent;
}
