cmake_minimum_required(VERSION 3.10)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Игровая библиотека
file(GLOB_RECURSE GAME_SRC "src/*.cpp")
list(FILTER GAME_SRC EXCLUDE REGEX ".*/main\\.cpp$")   # точно удаляем main.cpp

add_library(my_game_lib STATIC ${GAME_SRC})
target_include_directories(my_game_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Исполняемый файл игры
add_executable(my_game src/main.cpp)
target_link_libraries(my_game PRIVATE my_game_lib)

# Google Test
enable_testing()
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Тесты
file(GLOB_RECURSE TEST_SRC "tests/*.cpp")

add_executable(my_game_tests
    ${TEST_SRC}
)

target_link_libraries(my_game_tests
    PRIVATE
        my_game_lib     # код игры (без main)
        gtest_main
        pthread
)

target_include_directories(my_game_tests
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

add_test(NAME AllTests COMMAND my_game_tests)
