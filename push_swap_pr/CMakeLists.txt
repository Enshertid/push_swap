cmake_minimum_required(VERSION 3.14)
project(push_swap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(push_swap push_swap.c push_swap.h list_functions.c operations_for_singlestack.c useful_functions_forstack.c operations_for_bothstacks.c)
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)
