cmake_minimum_required(VERSION 3.21)
project(PureMVC)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES src/Core/Controller.cpp)
list(APPEND SOURCES src/Core/Model.cpp)
list(APPEND SOURCES src/Patterns/Proxy/Proxy.cpp)
list(APPEND SOURCES src/Patterns/Command/MacroCommand.cpp)
list(APPEND SOURCES src/Patterns/Command/SimpleCommand.cpp)
list(APPEND SOURCES src/Patterns/Observer/Notification.cpp)
list(APPEND SOURCES src/Patterns/Observer/Observer.cpp)
list(APPEND SOURCES src/Patterns/Mediator/Mediator.cpp)
add_library(PureMVC ${SOURCES} src/Core/Controller.cpp src/Interfaces/Controller.hpp)
find_package(Threads)
target_link_libraries(PureMVC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(PureMVC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(TestController test/Core/ControllerTest.cpp test/Core/ControllerTestCommand.cpp test/Core/ControllerTestCommand2.cpp test/Core/ControllerTestVO.hpp)
target_link_libraries(TestController PureMVC)

add_executable(TestModel test/Core/ModelTest.cpp test/Core/ModelTestProxy.cpp)
target_link_libraries(TestModel PureMVC)

set(TestMacroCommand test/Patterns/Command/MacroCommandTest.cpp)
list(APPEND TestMacroCommand test/Patterns/Command/MacroCommandTestCommand.cpp)
list(APPEND TestMacroCommand test/Patterns/Command/MacroCommandTestSub1Command.cpp)
list(APPEND TestMacroCommand test/Patterns/Command/MacroCommandTestSub2Command.cpp)
list(APPEND TestMacroCommand test/Patterns/Command/MacroCommandTestVO.cpp)
add_executable(TestMacroCommand ${TestMacroCommand})
target_link_libraries(TestMacroCommand PureMVC)

set(TestSimpleCommand test/patterns/command/SimpleCommandTest.cpp)
list(APPEND TestSimpleCommand test/patterns/command/SimpleCommandTestCommand.cpp)
list(APPEND TestSimpleCommand test/patterns/command/SimpleCommandTest.cpp)
list(APPEND TestSimpleCommand test/patterns/command/SimpleCommandTestVO.cpp)
add_executable(TestSimpleCommand ${TestSimpleCommand})
target_link_libraries(TestSimpleCommand PureMVC)

add_executable(TestNotification test/Patterns/Observer/NotificationTest.cpp)
target_link_libraries(TestNotification PureMVC)

add_executable(TestObserver test/Patterns/Observer/ObserverTest.cpp)
target_link_libraries(TestObserver PureMVC)

add_executable(TestMediator test/Patterns/Mediator/MediatorTest.cpp)
target_link_libraries(TestMediator PureMVC)

add_executable(TestProxy test/Patterns/Proxy/ProxyTest.cpp)
target_link_libraries(TestProxy PureMVC)
