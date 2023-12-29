add_executable(TestController
        Core/ControllerTest.cpp
        Core/ControllerTestCommand.cpp
        Core/ControllerTestCommand2.cpp
        Core/ControllerTestVO.hpp
        Patterns/Command/MacroCommandTestCommand.cpp
        Patterns/Command/MacroCommandTestSub1Command.cpp
        Patterns/Command/MacroCommandTestSub2Command.cpp)
target_link_libraries(TestController PureMVC)
add_test(NAME TestController COMMAND TestController)

add_executable(TestModel Core/ModelTest.cpp
        Core/ModelTestProxy.cpp)
target_link_libraries(TestModel PureMVC)
add_test(NAME TestModel COMMAND TestModel)

add_executable(TestView Core/ViewTest.cpp
        Core/ViewTestMediator.cpp
        Core/ViewTestMediator2.cpp
        Core/ViewTestMediator3.cpp
        Core/ViewTestMediator4.cpp
        Core/ViewTestMediator5.cpp
        Core/ViewTestMediator6.cpp
        Core/ViewTestObject.hpp)
target_link_libraries(TestView PureMVC)
add_test(NAME TestView COMMAND TestView)

add_executable(TestMacroCommand
        Patterns/Command/MacroCommandTestCommand.cpp
        Patterns/Command/MacroCommandTestSub1Command.cpp
        Patterns/Command/MacroCommandTestSub2Command.cpp
        Patterns/Command/MacroCommandTestVO.cpp
        Patterns/Command/MacroCommandTest.cpp)
target_link_libraries(TestMacroCommand PureMVC)
add_test(NAME TestMacroCommand COMMAND TestMacroCommand)

add_executable(TestSimpleCommand patterns/command/SimpleCommandTest.cpp
        patterns/command/SimpleCommandTestCommand.cpp
        patterns/command/SimpleCommandTestVO.cpp)
target_link_libraries(TestSimpleCommand PureMVC)
add_test(NAME TestSimpleCommand COMMAND TestSimpleCommand)

add_executable(TestFacade Patterns/Facade/FacadeTest.cpp
        Patterns/Facade/FacadeTestCommand.cpp
        Patterns/Facade/FacadeTestVO.hpp)
target_link_libraries(TestFacade PureMVC)
add_test(NAME TestFacade COMMAND TestFacade)

add_executable(TestNotifier Patterns/Facade/TestNotifier.cpp
        Patterns/Facade/FacadeTestCommand.cpp
        Patterns/Facade/FacadeTestVO.hpp)
target_link_libraries(TestNotifier PureMVC)
add_test(NAME TestNotifier COMMAND TestNotifier)

add_executable(TestNotification Patterns/Observer/NotificationTest.cpp)
target_link_libraries(TestNotification PureMVC)
add_test(NAME TestNotification COMMAND TestNotification)

add_executable(TestObserver Patterns/Observer/ObserverTest.cpp)
target_link_libraries(TestObserver PureMVC)
add_test(NAME TestObserver COMMAND TestObserver)

add_executable(TestMediator Patterns/Mediator/MediatorTest.cpp)
target_link_libraries(TestMediator PureMVC)
add_test(NAME TestMediator COMMAND TestMediator)

add_executable(TestProxy Patterns/Proxy/ProxyTest.cpp)
target_link_libraries(TestProxy PureMVC)
add_test(NAME TestProxy COMMAND TestProxy)
