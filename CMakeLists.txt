cmake_minimum_required(VERSION 3.10)
project(SimpleFactory VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demo
   src/ConceptualExample.cpp
   src/Documents.cpp
   src/MobilePhones.cpp
   src/Pizza.cpp
   src/Points.cpp
   src/Program.cpp
)

enable_testing()
add_test(NAME test COMMAND demo)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "apkent@example.com")

install(TARGETS demo DESTINATION /usr/local/bin)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "apkent@example.com")
include(CPack)
