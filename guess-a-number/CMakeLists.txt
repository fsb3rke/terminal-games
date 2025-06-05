cmake_minimum_required(VERSION 3.10)
project(guess-a-number)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
else()
    add_compile_options(-Wall -Werror -Wpedantic)
endif()


include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCES
    src/main.cpp
    src/random_utils.cpp
)

add_executable(guess-a-number ${SOURCES})

target_link_libraries(guess-a-number ${CURSES_LIBRARIES})
