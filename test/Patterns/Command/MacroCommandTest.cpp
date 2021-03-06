#include "MacroCommandTest.hpp"
#include "MacroCommandTestCommand.hpp"
#include "MacroCommandTestVO.hpp"
#include "Interfaces/Notification.hpp"
#include <iostream>

using PureMVC::Patterns::Notification;

int main() {
    testMacroCommandExecute();
    std::cout << "MacroCommand Tests Passed";
    return 0;
}

void testMacroCommandExecute() {
    auto vo = MacroCommandTestVO{5};

    auto notification = new Notification("MacroCommandTest", &vo);

    auto command = new MacroCommandTestCommand();

    command->execute(notification);

    assert(vo.result1 == 10);
    assert(vo.result2 == 25);

    delete notification;
    delete command;
}