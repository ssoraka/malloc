//
// Created by Suzette Soraka on 10/4/20.
//

#ifndef MALLOC_MALLOC_H
# define MALLOC_MALLOC_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/mman.h>
# define SYMBOLS "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ"
# define FAIL_MMAP -1
# define BYTES_IN_LINE 16

/*
 * (void *)(-1)
 */

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
	t_page			page;
}					t_pages;

/*
** хранилище выделенной памяти
*/

typedef struct s_store
{
	struct s_pages	p[TYPE_COUNT];
	int				is_init;
}					t_store;

void	ft_bzero(void *s, size_t n);
void	ft_putchar(int chr);
void	ft_putstr(char *str);
void	ft_memset(void *s, size_t n, char chr);
void	ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strrevers(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_isprint(int c);
int		is_null(void *ptr, void **addr);

t_page	*new_page(size_t size);
int		destroy_page(t_page *page);
size_t	ft_get_size(size_t size);
size_t	ft_round(size_t size, int mod);
void	insert_page_after_page(t_page *prev, t_page *page);
void	cut_page(t_page *page);
t_page	*next_page(t_page *page);

void	*malloc1(size_t size);
void	free1(void *ptr);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t count, size_t size);

void	ft_print_addres(void *ptr, int fd);
void	ft_print_page(t_page *page);
void	ft_print_mem(void);

void	show_alloc_mem(void);

t_store	*get_store(void);
void	free_store(void);
void	store_page(t_page *page);
t_page	*get_page_from_store(size_t size);
void	print_store(void);

void	insert_start_page(t_page *page, int type);
int		is_end(t_page *page, int type);
t_page	*get_start_page(int type);

int		type_from_size(size_t size);
int		size_from_type(int type);

#endif //MALLOC_MALLOC_H
