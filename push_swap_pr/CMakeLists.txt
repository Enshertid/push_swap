cmake_minimum_required(VERSION 3.14)
project(push_swap_pr)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(push_swap_pr push_swap.c push_swap.h list_functions.c operations_for_singlestack.c
        useful_functions_forstack.c operations_for_bothstacks.c
        parsing.c check_op.c filling_op_point.c pre_sort_stacks.c use_operations.c functions_for_operations.c)
target_link_libraries(push_swap_pr ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a)
