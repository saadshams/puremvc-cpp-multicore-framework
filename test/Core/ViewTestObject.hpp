#ifndef PUREMVC_VIEWTESTOBJECT_HPP
#define PUREMVC_VIEWTESTOBJECT_HPP

struct ViewTestObject {
    int value = 0;
    bool onRegisterCalled = false;
    bool onRemoveCalled = false;
    std::string lastNotification;
};

#endif //PUREMVC_VIEWTESTOBJECT_HPP
