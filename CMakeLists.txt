cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)


include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.278.tar.gz"
        SHA1 "35fa55bc1dfcf9f4d7264f8bb26cd1759ce1ae07"
)

project(tsisa_lab06)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")



hunter_add_package(Boost COMPONENTS system graph)
find_package(Boost CONFIG REQUIRED system graph)

add_library(tsisa_lab06 STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
        )


add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
        )


include_directories(SYSTEM ${Boost_INCLUDE_DIRS})


target_link_libraries(tsisa_lab06 PUBLIC ${Boost_LIBRARIES})
target_link_libraries(main PUBLIC tsisa_lab06 PUBLIC ${Boost_LIBRARIES})

enable_testing()
add_test(NAME unit_tests COMMAND tests)

