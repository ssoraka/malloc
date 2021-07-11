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

	print_func("malloc", START | SIZE, NULL, size);
	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, IS_MALLOC);
	pthread_mutex_unlock(get_mutex());
	print_func("malloc", END | PTR, ptr, size);
	return (ptr);
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	size = size * count;
	print_func("calloc", START | SIZE, NULL, size);
	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, IS_CALLOC);
	pthread_mutex_unlock(get_mutex());
	print_func("calloc", END | PTR, ptr, size);
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	print_func("realloc", START | PTR | SIZE, ptr, size);
	pthread_mutex_lock(get_mutex());
	if (!ptr)
		ptr = ft_malloc(size, IS_MALLOC);
	else
		ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(get_mutex());
	print_func("realloc", END | PTR, ptr, size);
	return (ptr);
}

void	free(void *ptr)
{
	if (!ptr)
		return ;
	print_func("free", START | PTR, ptr, 0);
	pthread_mutex_lock(get_mutex());
	ft_free(ptr);
	pthread_mutex_unlock(get_mutex());
	print_func("free", END, ptr, 0);
}
