cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

include(CTest)
enable_testing()

set(ENGINE_SOURCE)
set(ENGINE_HEADER)

set(ENGINE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include(collision/CMakeLists.txt)
include(geometry/CMakeLists.txt)
include(render/CMakeLists.txt)
include(scene/CMakeLists.txt)
include(util/CMakeLists.txt)

add_library(${PROJECT_NAME}
    ${ENGINE_SOURCE}
    ${ENGINE_HEADER}
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC "${ENGINE_ROOT}"
    ${PROJECT_NAME} PUBLIC "${ENGINE_ROOT}/external"
)

# OpenGL
set(OpenGL_GL_PREFERENCE GLVND) 
find_package(OpenGL REQUIRED)
message(STATUS "OPENGL_INCLUDE_DIR: ${OPENGL_INCLUDE_DIR}")
include_directories(${OPENGL_INCLUDE_DIR})

if(APPLE)
    target_link_libraries(${PROJECT_NAME}
        "-framework OpenGL"
    )
elseif(LINUX)
    target_link_libraries(${PROJECT_NAME}
        GL
    )
else()
    message( FATAL_ERROR "Unsupported platform, CMake will exit" )
endif()

# GLM
add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(TOOLS_DIR "${ENGINE_ROOT}/tools")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    
    COMMAND python3 ${TOOLS_DIR}/genheader.py
)