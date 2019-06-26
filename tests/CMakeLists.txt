cmake_minimum_required(VERSION 3.2)

project(tests C)
file(GLOB TEST_SRC ../src/*.c)
list(FILTER TEST_SRC  EXCLUDE REGEX ".*/main.c")
message(${TEST_SRC})
set(TESTS test_mat test_mat3 test_mat_inverse)

link_directories(minilibx libft)
foreach(TEST ${TESTS})
    add_executable(${TEST} ${TEST}.c ${TEST_SRC})
    target_link_libraries(${TEST} libmlx.a -lXext -lX11 -lm -lft)
    target_include_directories(${TEST} PUBLIC ../includes ../minilibx ../libft)
endforeach()
