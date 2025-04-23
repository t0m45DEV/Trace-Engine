cmake_minimum_required(VERSION 3.5)

project(videoGame LANGUAGES C VERSION 0.1.0)

add_compile_options(-fsanitize=address -Wall -Wextra -Werror -O3)
add_link_options(-fsanitize=address)

file(GLOB src src/*.c)
add_executable(${PROJECT_NAME} ${src})

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src
)

# Testing

set(TESTS_FILE_NAME run_tests)

file(GLOB tests tests/testing.c src/trigonometry.c)
add_executable(${TESTS_FILE_NAME} ${tests})
target_link_libraries(${TESTS_FILE_NAME} cunit m)

add_test(NAME test_instatiator
        COMMAND test_instatiator)

# End testing

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} m)
install(TARGETS ${PROJECT_NAME})
