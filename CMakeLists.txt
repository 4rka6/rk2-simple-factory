cmake_minimum_required(VERSION 3.10)
project(SimpleFactory VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

add_library(factory STATIC 
    src/Factory.cpp
)

target_include_directories(factory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(BUILD_TESTS)
    enable_testing()
    add_executable(test_factory tests/test_factory.cpp)
    target_link_libraries(test_factory factory)
    add_test(NAME SimpleFactoryTest COMMAND test_factory)
endif()

include(CPack)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "4rka6 <gurkovskija@gmail.com>")
