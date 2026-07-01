cmake_minimum_required(VERSION 3.20)

project(ConsoleFightingGame VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(ConsoleFightingGame
    src/main.cpp
    src/characters/base/character.cpp
    src/characters/player.cpp
    src/characters/enemy.cpp
    src/components/healthcomponent.cpp
    src/components/weaponcomponent.cpp
    src/components/weapondatabase.cpp
    src/game.cpp
    src/battle.cpp
    src/utility/console_utils.cpp
)

target_include_directories(ConsoleFightingGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ConsoleFightingGame PRIVATE nlohmann_json::nlohmann_json)

if(MSVC)
    target_compile_options(ConsoleFightingGame PRIVATE /W3 /permissive-)
else()
    target_compile_options(ConsoleFightingGame PRIVATE -Wall -Wextra -pedantic)
endif()

add_custom_command(TARGET ConsoleFightingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:ConsoleFightingGame>/data
    COMMENT "Copying data folder to output directory"
)
