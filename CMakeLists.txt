cmake_minimum_required(VERSION 3.2)

set(NAME fdf)
project(${NAME} C)

set(GCC_COVERAGE_COMPILE_FLAGS "${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra -Werror")

file(GLOB SRC src/*.c)

#     fdf
link_directories(minilibx libft)
include_directories(minilibx includes libft)
link_libraries(-lft libmlx.a -lXext -lX11 -lm)
add_executable(${NAME} ${SRC})

# end fdf

add_subdirectory(tests)
