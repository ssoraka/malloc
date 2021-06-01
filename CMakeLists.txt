cmake_minimum_required(VERSION 3.17)
project(malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc src/main.c includes/malloc.h src/malloc.c src/debug.c src/from_libft.c src/free.c src/show_alloc_mem.c src/store.c src/page.c src/root.c src/page_size.c src/test.c)