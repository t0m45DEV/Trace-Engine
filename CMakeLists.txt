cmake_minimum_required(VERSION 3.5)

project(videoGame LANGUAGES C VERSION 0.1.0)

add_compile_options(-Wall -Wextra -Werror)

file(GLOB src src/*.c)
add_executable(${PROJECT_NAME} ${src})

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m)

install(TARGETS ${PROJECT_NAME})
