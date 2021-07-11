/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

size_t	size_from_type(t_type type)
{
	int	test;

	test = get_store()->test;
	if (type == TINY && test)
		return (256);
	if (type == SMALL && test)
		return (512);
	if (type == TINY)
		return (getpagesize() * TINY_SIZE);
	if (type == SMALL)
		return (getpagesize() * SMALL_SIZE);
	return (0);
}

t_type	type_from_page_size(size_t size)
{
	if (size <= size_from_type(TINY))
		return (TINY);
	if (size <= size_from_type(SMALL))
		return (SMALL);
	return (LARGE);
}

t_type	type_from_alloc_size(size_t size)
{
	size_t	max;

	max = (size_from_type(TINY) - sizeof(t_page)) / get_store()->alloc_count
		- sizeof(t_block);
	if (size <= max)
		return (TINY);
	max = (size_from_type(SMALL) - sizeof(t_page)) / get_store()->alloc_count
		- sizeof(t_block);
	if (size <= max)
		return (SMALL);
	return (LARGE);
}

size_t	get_page_size_from_alloc(size_t size)
{
	t_type	type;

	type = type_from_alloc_size(size);
	if (type == TINY || type == SMALL)
		return (size_from_type(type));
	return (calculate_block_size(size) + sizeof(t_page));
}
