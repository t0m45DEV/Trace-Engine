cmake_minimum_required(VERSION 3.5)

project(videoGame LANGUAGES C VERSION 0.1.0)

add_compile_options(-Wall -Wextra -Werror -O3)

file(GLOB src src/*.c)
add_executable(${PROJECT_NAME} ${src})

if (WIN32)
    set(CMAKE_MODULE_PATH "C:/Users/Tomas/Documents/c_libs")
    set(SDL2_PATH "C:/Users/Tomas/Documents/c_libs/SDL2-2.30.10/x86_64-w64-mingw32")
endif (WIN32)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

find_library(MATH_LIBRARY m)

include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${MATH_LIBRARY})

install(TARGETS ${PROJECT_NAME})
