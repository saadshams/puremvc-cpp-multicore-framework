#include "ViewTestMediator6.hpp"
#include "Interfaces/Facade.hpp"

ViewTestMediator6::ViewTestMediator6(const std::string &name, const ViewTestObject *object) : Mediator(name, object) {

}

std::vector<std::string> ViewTestMediator6::listNotificationInterests() {
    return {NOTE6};
}

void ViewTestMediator6::handleNotification(Notification *notification) {
    getFacade()->removeMediator(getMediatorName());
}

void ViewTestMediator6::onRemove() {
    ((ViewTestObject *) _viewComponent)->counter++;
}
