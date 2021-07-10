/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <pthread.h>
# include "malloc_structs.h"
# include "../libft/libft.h"

#define DYLD_FORCE "DYLD_FORCE_FLAT_NAMESPACE"
#define COLORS "MALLOC_COLORS"
#define DEBUG "MALLOC_DEBUG"
#define MARK "MALLOC_MARK_MEMORY"
#define TEST "MALLOC_TEST"


# define ALLOCS_COUNT 100
# define PAGE_COUNT 50
# define TEST_ALLOCS_COUNT 3
# define TEST_PAGE_COUNT 2


# define NO_PARAMS  0
# define IS_CALLOC  1
# define IS_FREE    2
# define IS_MALLOC  4

# define MALLOC_SYMB "malloc_"
# define FREE_SYMB "free_"
# define BYTES_IN_LINE 64
# define SYMBOLS "0123456789ABCDEF"
# define FAIL_MMAP -1
/*
** (void *)(-1)
*/

typedef enum e_type		t_type;
typedef enum e_status	t_stat;
typedef pthread_mutex_t	t_mut;
extern t_mut			g_mutex;
extern t_store			g_store;

/*
** mutex.c
*/
t_mut	*get_mutex(void);

/*
** math.c
*/
size_t	get_floor(size_t size, size_t mod);
size_t	calculate_block_size(size_t size);

/*
** page.c
*/
t_page	*new_page(size_t size);
int		destroy_page(t_page *page);
void	insert_page_after_page(t_page *prev, t_page *page);
void	cut_page(t_page *page);
t_page	*next_page(t_page *page);

/*
** pages.c
*/
void	insert_page(t_page *page, t_type type);
int		is_end(t_page *page, t_type type);
t_page	*get_start_page(t_type type);

/*
** page_size.c
*/
size_t	get_page_size_from_alloc(size_t size);
size_t	calculate_block_size(size_t size);
t_type	type_from_alloc_size(size_t size);
t_type	type_from_page_size(size_t size);
size_t	size_from_type(t_type type);

/*
** print.c
*/
t_stat	is_mem(void *ptr, t_page *page);
void	ft_print_char(unsigned char chr, t_stat is_mem);
void	ft_print_chars(char *ptr, int count);
void	ft_print_addres(void *ptr, int fd);

/*
** debug.c
*/
void	ft_print_page(t_page *page);
void	ft_print_mem(void);
void	*debug(t_page *page, void *ptr, size_t size, size_t params);

/*
** show_alloc_mem.c
*/
void	show_alloc_mem(void);

/*
** error.c
*/
void	exit_with_error(void *ptr, char *msg1, char *msg2);

/*
** ft_free_realloc.c
*/
void	ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

/*
** ft_malloc.c
*/
void	*ft_malloc(size_t size, size_t params);

/*
** store.c
*/
void	free_store(void);
void	store_page(t_page *page);
t_store	*get_store(void);
void	print_store(void);

/*
** store2.c
*/

void	init_store(t_store *store);
t_page	*get_page_from_store(size_t size);

/*
** malloc.c
*/
void	*malloc(size_t size);
void	*calloc(size_t count, size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

#endif
