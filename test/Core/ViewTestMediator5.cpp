#include "ViewTestMediator5.hpp"

ViewTestMediator5::ViewTestMediator5(const ViewTestObject *object) : Mediator(NAME, object) {

}

std::vector<std::string> ViewTestMediator5::listNotificationInterests() {
    return {NOTE5};
}

void ViewTestMediator5::handleNotification(Notification *notification) {
    ((ViewTestObject *) _viewComponent)->counter++;
}