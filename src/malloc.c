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

#include "../includes/ft_malloc.h"

void	*malloc(size_t size)
{
	void	*ptr;

	ft_putstr("malloc start ");
	ft_putnbr(size);
	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, IS_MALLOC);
	pthread_mutex_unlock(get_mutex());
	ft_putstr(" end ");
	ft_print_addres(ptr, 1);
	ft_putstr("\n");
	return (ptr);
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	ft_putstr("calloc start ");
	ft_putnbr(count);
	ft_putstr(" ");
	ft_putnbr(size);
	size = size * count;
	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, IS_CALLOC);
	pthread_mutex_unlock(get_mutex());
	ft_putstr(" end ");
	ft_print_addres(ptr, 1);
	ft_putstr("\n");
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	ft_putstr("realloc start ");
	ft_putnbr(size);
	ft_putstr(" ");
	ft_print_addres(ptr, 1);
	pthread_mutex_lock(get_mutex());
	if (!ptr) {
		ptr = ft_malloc(size, IS_MALLOC);
	} else {
		ptr = ft_realloc(ptr, size);
	}
	pthread_mutex_unlock(get_mutex());
	ft_putstr(" end ");
	ft_print_addres(ptr, 1);
	ft_putstr("\n");

	return (ptr);
}

void	free(void *ptr)
{
	if (!ptr) {
		return ;
	}
	ft_putstr("free start ");
	ft_print_addres(ptr, 1);
	pthread_mutex_lock(get_mutex());
	ft_free(ptr);
	pthread_mutex_unlock(get_mutex());
	ft_putstr(" end\n");
}
