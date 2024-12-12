cmake_minimum_required(VERSION 3.5)

project(videoGame LANGUAGES C VERSION 0.1.0)

add_compile_options(-Wall -Wextra -Werror -O3)

file(GLOB src src/*.c)
add_executable(${PROJECT_NAME} ${src})

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} SDL2 ${OPENGL_LIBRARIES} m)

install(TARGETS ${PROJECT_NAME})
