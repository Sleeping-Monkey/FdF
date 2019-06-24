cmake_minimum_required(VERSION 3.2)

project(tests C)
file(GLOB TEST_SRC )

set(TESTS test_mat)

foreach(TEST ${TESTS})
    add_executable(${TEST} ${TEST}.c ${TEST_SRC})
endforeach()
