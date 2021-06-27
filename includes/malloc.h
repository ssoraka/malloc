/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <pthread.h>
# define SYMBOLS "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ"
# define FAIL_MMAP -1
# define BYTES_IN_LINE 16
# include "malloc_structs.h"
# include "../libft/libft.h"
/*
 * (void *)(-1)
 */

extern pthread_mutex_t	g_mutex;


t_page	*new_page(size_t size);
int		destroy_page(t_page *page);
size_t	ft_get_size(size_t size);
size_t	ft_round(size_t size, int mod);
void	insert_page_after_page(t_page *prev, t_page *page);
void	cut_page(t_page *page);
t_page	*next_page(t_page *page);

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

void	*malloc(size_t size);
void	*calloc(size_t count, size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

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
size_t	size_from_type(int type);

#endif //MALLOC_MALLOC_H
