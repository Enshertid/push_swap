cmake_minimum_required(VERSION 3.14)
project(push_swap_checker C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(push_swap_checker checker.c checker.h operations_for_bothstacks.c operations_for_singlestack.c useful_functions_forstack.c list_functions.c parsing.c)
target_link_libraries(push_swap_checker ${CMAKE_SOURCE_DIR}/libft/libft.a)