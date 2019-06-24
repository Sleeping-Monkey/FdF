cmake_minimum_required(VERSION 3.2)

project(tests C)
file(GLOB TEST_SRC )

set(MINILIBX_DIR ${CMAKE_BINARY_DIR}/../minilibx)
link_directories(${MINILIBX_DIR})
include_directories(${MINILIBX_DIR} ../includes)
link_libraries(libmlx.a -lXext -lX11 -lm)

set(TESTS )
foreach(TEST ${TESTS})
    add_executable(${TEST} ${TEST}.c ${TEST_SRC})
endforeach()
# end fdf
