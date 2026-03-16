cmake_minimum_required(VERSION 3.25)
project(homeworks C)

add_compile_options(-Wall -Wextra -pedantic)

add_library(bstLib src/bst.c)
add_executable(bst src/main.c)
target_link_libraries(bst PRIVATE bstLib)
