cmake_minimum_required(VERSION 3.23)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
project(adventofcode-2022-day01 LANGUAGES CXX)

find_package(cppfront CONFIG REQUIRED)

# if (NOT "$ENV{PATH}" STREQUAL "")
#     set(PATH "$ENV{PATH}" CACHE INTERNAL "Copied from environment variable")
# endif()
# message("PATH = ${PATH}")

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    COMMAND cppfront ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp2
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp2
    COMMENT "Run cppfront on .cpp2 files"
)

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE cppfront::cppfront)

# install(TARGETS ${CMAKE_PROJECT_NAME})