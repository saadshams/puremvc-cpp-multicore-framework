#ifndef PUREMVC_VIEWTESTOBJECT_HPP
#define PUREMVC_VIEWTESTOBJECT_HPP

struct ViewTestObject {
    int value = 0;
    bool onRegisterCalled = false;
    bool onRemoveCalled = false;
    std::string lastNotification;
    int counter = 0;
};

#endif //PUREMVC_VIEWTESTOBJECT_HPP
