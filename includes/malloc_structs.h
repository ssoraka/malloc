//
// Created by Suzette Soraka on 6/6/21.
//

#ifndef MALLOC_MALLOC_STRUCTS_H
# define MALLOC_MALLOC_STRUCTS_H

enum				e_status
{
	FREE = 0,
	BLOCK = 1,
	ALLOC = 2,
	PAGE = 3,
	NUM = 4,
	STATUS_COUNT = 5
}					t_status;

enum				e_type
{
	TINY = 0,
	SMALL = 1,
	LARGE = 2,
	STORE_COUNT = 3,
	USED = 3,
	TYPE_COUNT = 4
}					t_type;

enum				e_size
{
	TINY_SIZE = 1,
	SMALL_SIZE = 8
}					t_size;

/*
** этот список будет сохранять указатели на выделенную память
*/

typedef struct s_block
{
	struct s_block	*next;
	size_t			used;
	size_t			empty;
}					t_block;

/*
** одна страница выделенной памяти
*/

typedef struct s_page
{
	size_t			size;
	struct s_page	*prev;
	struct s_page	*next;
	size_t			alloc_count;
	struct s_block	alloc;
}					t_page;

typedef struct s_pages
{
	struct s_page	page;
}					t_pages;

/*
** хранилище выделенной памяти
*/

typedef struct s_store
{
	struct s_pages	p[TYPE_COUNT];
	int				is_init;
}					t_store;

#endif //MALLOC_MALLOC_STRUCTS_H
