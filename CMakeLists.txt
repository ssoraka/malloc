cmake_minimum_required(VERSION 3.17)
project(malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc garbage/main.c includes/ft_malloc.h src/mutex.c src/error.c src/print.c src/math.c src/malloc.c src/ft_malloc.c src/debug.c garbage/from_libft.c src/ft_free_realloc.c src/show_alloc_mem.c src/store.c src/store2.c src/page.c src/pages.c src/page_size.c includes/malloc_structs.h)