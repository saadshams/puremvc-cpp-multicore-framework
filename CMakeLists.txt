cmake_minimum_required(VERSION 3.21)
project(PureMVC)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES src/Patterns/Proxy/Proxy.cpp)
list(APPEND SOURCES src/Patterns/Mediator/Mediator.cpp)
add_library(PureMVC ${SOURCES})
find_package(Threads)
target_link_libraries(PureMVC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(PureMVC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(TestProxy test/Patterns/Proxy/TestProxy.cpp)
target_link_libraries(TestProxy PureMVC)

add_executable(TestMediator test/Patterns/Mediator/MediatorTest.cpp)
target_link_libraries(TestMediator PureMVC)