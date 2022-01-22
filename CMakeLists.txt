cmake_minimum_required(VERSION 3.0.0)
project(GLRayTrace VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/TestScene.h
    src/TestScene.cpp
)

add_subdirectory(engine)

target_include_directories(
    ${PROJECT_NAME} PRIVATE "./"
    ${PROJECT_NAME} PRIVATE "./engine"
)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

find_library(engine ${CMAKE_SOURCE_DIR}/engine)
target_link_libraries(${PROJECT_NAME} Engine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_definitions(-DWRITABLE_PATH="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
