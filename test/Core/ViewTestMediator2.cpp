#include "ViewTestMediator2.hpp"

ViewTestMediator2::ViewTestMediator2(ViewTestObject *object) : Mediator(NAME, object) {

}

std::vector<std::string> ViewTestMediator2::listNotificationInterests() {
    return {NOTE1, NOTE2};
}

void ViewTestMediator2::handleNotification(Notification *notification) {
    ((ViewTestObject *)_viewComponent)->lastNotification = notification->getName();
}
