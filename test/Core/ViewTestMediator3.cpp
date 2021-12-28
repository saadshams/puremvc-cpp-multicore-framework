#include "ViewTestMediator3.hpp"

ViewTestMediator3::ViewTestMediator3(const ViewTestObject *object) : Mediator(NAME, object) {

}

std::vector<std::string> ViewTestMediator3::listNotificationInterests() {
    return {NOTE3};
}

void ViewTestMediator3::handleNotification(Notification *notification) {
    ((ViewTestObject *)_viewComponent)->lastNotification = notification->getName();
}
