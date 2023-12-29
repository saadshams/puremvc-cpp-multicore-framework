cmake_minimum_required(VERSION 3.26)
project(PureMVC)

set(CMAKE_CXX_STANDARD 23)

add_library(PureMVC src/Core/Controller.cpp
        src/Core/Model.cpp
        src/Core/View.cpp
        src/Patterns/Command/MacroCommand.cpp
        src/Patterns/Command/SimpleCommand.cpp
        src/Patterns/Facade/Facade.cpp
        src/Patterns/Facade/Notifier.cpp
        src/Patterns/Observer/Notification.cpp
        src/Patterns/Observer/Observer.cpp
        src/Patterns/Mediator/Mediator.cpp
        src/Patterns/Proxy/Proxy.cpp)
find_package(Threads)
target_link_libraries(PureMVC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(PureMVC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(test)
