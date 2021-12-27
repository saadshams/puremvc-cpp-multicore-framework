#include "ViewTestMediator4.hpp"

ViewTestMediator4::ViewTestMediator4(const ViewTestObject *object) : Mediator(NAME, object) {

}

void ViewTestMediator4::onRegister() {
    ((ViewTestObject *)_viewComponent)->onRegisterCalled = true;
}

void ViewTestMediator4::onRemove() {
    ((ViewTestObject *)_viewComponent)->onRemoveCalled = true;
}

const ViewTestObject *ViewTestMediator4::viewTestObject() const {
    return (ViewTestObject *)_viewComponent;
}
