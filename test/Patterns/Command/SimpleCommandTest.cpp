#include "SimpleCommandTest.hpp"
#include "SimpleCommandTestVO.hpp"
#include "Interfaces/Notification.hpp"
#include "SimpleCommandTestCommand.hpp"
#include <iostream>

using PureMVC::Patterns::Notification;

int main() {
    testSimpleCommandExecute();
    std::cout << "SimpleCommand Tests Passed";
    return 0;
}

void testSimpleCommandExecute() {
    auto vo = SimpleCommandTestVO{5};

    auto *notification = new Notification("SimpleCommentTestNote", &vo);

    auto *command = new SimpleCommandTestCommand();

    command->execute(notification);

    assert(vo.result == 10);

    delete notification;
    delete command;
}