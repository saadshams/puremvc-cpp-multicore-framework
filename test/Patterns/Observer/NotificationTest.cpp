#include "NotificationTest.hpp"
#include "Interfaces/Notification.hpp"

#include <iostream>

using PureMVC::Patterns::Observer::Notification;

int main() {
    testNameAccessors();
    testBodyAccessors();
    testConstructor();
    testToString();
    std::cout << "Notification Tests Passed";
    return 0;
}

void testNameAccessors() {
    auto *note = new Notification("TestNote");

    assert(note->getName() == "TestNote");

    delete note;
}

void testBodyAccessors() {
    int value = 5;
    auto *note = new Notification("");

    note->setBody(&value);

    assert(*(int *)note->getBody() == 5);

    delete note;
}

void testConstructor() {
    int value = 5;
    auto *note = new Notification("TestNote", &value, "TestNoteType");

    assert(note->getName() == "TestNote");
    assert(*(int *)note->getBody() == 5);
    assert(note->getType() == "TestNoteType");

    delete note;
}

void testToString() {
    int value[] = {1, 3, 5};
    auto *note = new Notification("TestNote", value, "TestType");
    std::string msg = "Notification Name: TestNote\nBody: ";
    msg += typeid(void const*).name();
    msg += "\nType: TestType";

    assert(note->toString() == msg);

    delete note;
}
