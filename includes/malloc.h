//
// Created by Suzette Soraka on 10/4/20.
//

#ifndef MALLOC_MALLOC_H
#define MALLOC_MALLOC_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/mman.h>

# define SYMBOLS "0123456789ABCDEF"
# define FAIL_MMAP (void *)(-1)

enum					e_status
{
	FREE,
	BLOCK,
	ALLOC,
	PAGE,
	STATUS_COUNT
};

enum					e_type
{
	TINY,
	SMALL,
	LARGE,
	TYPE_COUNT
}					t_type;

enum					e_size
{
	TINY_SIZE = 1,
	SMALL_SIZE = 8
}					t_size;

/*
** этот список будет сохранять указатели на выделенную память
*/
typedef struct		s_block {
	struct s_block	*next;
	size_t			used;
	size_t			empty;
}					t_block;

/*
** одна страница выделенной памяти
*/
typedef struct		s_page {
	size_t			size;
	struct s_page	*prev;
	struct s_page	*next;
	size_t			alloc_count;
	struct s_block	alloc;
}					t_page;

/*
** список страниц выделенной памяти
*/
typedef struct		s_pages {
	struct s_page	*head;
	struct s_page	*last;
	size_t			count;
}					t_pages;

/*
** хранилище выделенной памяти
*/
typedef struct		s_store {
	t_page			*p[TYPE_COUNT];
	int				size[TYPE_COUNT];
	int 			is_init;
}					t_store;

typedef struct		s_root {
	t_page			page;
	t_page			*last;
	int 			is_init;
}					t_root;

void	ft_bzero(void *s, size_t n);
void	ft_putchar(int chr);
void	ft_putstr(char *str);
void	ft_memset(void *s, size_t n, char chr);
void	ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strrevers(char *str);
void	ft_putnbr(int n);

t_page	*new_page(int size);
int		destroy_page(t_page *page);
size_t	ft_get_size(size_t size);
size_t	ft_get_memory_size_on_page(t_page *page);
void	insert_page_after_page(t_page *prev, t_page *page);
void	cut_page(t_page *page);

t_root	*get_root();
t_page	*get_first_page();
void	add_page_in_root(t_page *page);
void	sub_page_from_root(t_page *page);

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_calloc(size_t size);

void	ft_print_page(t_page *page);
void	ft_page_to_str(t_page *page);
void	ft_print_mem();

void	show_alloc_mem();


t_store	*get_store();
void	free_store();
void	store_page(t_page *page);
t_page	*get_page_from_store(size_t size);

#endif //MALLOC_MALLOC_H
