cmake_minimum_required(VERSION 3.20)

project(ConsoleFightingGame VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ConsoleFightingGame
    src/main.cpp
    src/character.cpp
    src/player.cpp
    src/enemy.cpp
    src/game.cpp
    src/battle.cpp
    src/console_utils.cpp
)

target_include_directories(ConsoleFightingGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(ConsoleFightingGame PRIVATE /W3 /permissive-)
else()
    target_compile_options(ConsoleFightingGame PRIVATE -Wall -Wextra -pedantic)
endif()
