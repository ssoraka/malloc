/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*malloc(size_t size)
{
	void	*ptr;

	if (!size)
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	size = size * count;
	pthread_mutex_lock(&g_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}

