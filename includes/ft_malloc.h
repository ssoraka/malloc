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

# define SYMBOLS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define BYTES_IN_LINE 16
# define ALLOCS_COUNT 3
# define FAIL_MMAP -1
/*
 * (void *)(-1)
 */

extern pthread_mutex_t	g_mutex;
struct s_store			g_store;

/*
** math.c
*/
size_t	get_floor(size_t size, size_t mod);

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
void	*ft_malloc(size_t size);

/*
** store.c
*/
void	free_store(void);
void	init_store(t_store *store);
void	store_page(t_page *page);

/*
** store2.c
*/
void	print_store(void);
t_store	*get_store(void);
t_page	*get_page_from_store(size_t size);

/*
** malloc.c
*/
void	*malloc(size_t size);
void	*calloc(size_t count, size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

#endif //MALLOC_FT_MALLOC_H
