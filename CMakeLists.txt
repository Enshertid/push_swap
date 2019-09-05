cmake_minimum_required(VERSION 3.14)
project(push_swap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(push_swap main.c push_swap.h list_functions.c operations.c useful_functions_forstack.c checker.c)
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft/libft.a)
