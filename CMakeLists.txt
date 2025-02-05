cmake_minimum_required(VERSION 3.5)

project(videoGame LANGUAGES C VERSION 0.1.0)

add_compile_options(-fsanitize=address -Wall -Wextra -Werror -O3)
add_link_options(-fsanitize=address -static-libasan)

file(GLOB src src/*.c)
add_executable(${PROJECT_NAME} ${src})

if (WIN32)
    set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/libs)
    set(SDL2_PATH ${CMAKE_SOURCE_DIR}libs/SDL2-2.30.10)
endif (WIN32)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)

# Testing

set(TESTS_FILE_NAME run_tests)

file(GLOB tests tests/testing.c src/trigonometry.c)
add_executable(${TESTS_FILE_NAME} ${tests})
target_link_libraries(${TESTS_FILE_NAME} cunit m)

add_test(NAME test_instatiator
        COMMAND test_instatiator)

# End testing

if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} m)
    file(COPY ${CMAKE_SOURCE_DIR}/libs/SDL2.dll DESTINATION ${CMAKE_SOURCE_DIR}/cmake-build-debug)
else ()
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} m)
endif (WIN32)

install(TARGETS ${PROJECT_NAME})
