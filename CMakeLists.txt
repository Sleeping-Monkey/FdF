cmake_minimum_required(VERSION 3.2)

set(NAME fdf)
project(${NAME} C)

set(GCC_COVERAGE_COMPILE_FLAGS "${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra -Werror")

file(GLOB SRC src/*.c)

#     fdf
add_executable(${NAME} ${SRC})
target_include_directories(${NAME} PRIVATE includes minilibx)
target_link_directories(${NAME} PRIVATE minilibx)
target_link_libraries(${NAME} libmlx.a -lXext -lX11 -lm)
# end fdf

add_subdirectory(tests)
