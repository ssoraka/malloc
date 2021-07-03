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

	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, FALSE);
	pthread_mutex_unlock(get_mutex());
	return (ptr);
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	size = size * count;
	pthread_mutex_lock(get_mutex());
	ptr = ft_malloc(size, TRUE);
	pthread_mutex_unlock(get_mutex());
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (NULL);
	pthread_mutex_lock(get_mutex());
	ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(get_mutex());
	return (ptr);
}

void	free(void *ptr)
{
	if (!ptr)
		return ;
	pthread_mutex_lock(get_mutex());
	ft_free(ptr);
	pthread_mutex_unlock(get_mutex());
}
