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

#include "../includes/malloc.h"

/*
 * //	if (type == TINY)
 * //		return (getpagesize() * TINY_SIZE);
 * //	if (type == SMALL)
 * //		return (getpagesize() * SMALL_SIZE);
 */

size_t	size_from_type(t_type type)
{
	if (type == TINY)
		return (256);
	if (type == SMALL)
		return (512);
	return (0);
}

//size_t	ft_round(size_t size, size_t mod)
//{
//	return (size + (mod - size % mod) * (size % mod > 0));
//}

size_t	calculate_block_size(size_t size)
{
	return (size + size % sizeof(int) + sizeof(t_block));
}

size_t	ft_calculate_page_size(size_t size)
{
	return (calculate_block_size(size) * ALLOCS_COUNT + sizeof(t_page));
}

size_t	calculate_large_page_size(size_t size)
{
	return (calculate_block_size(size) + sizeof(t_page));
}

t_type	type_from_size(size_t page_size)
{
	if (page_size <= size_from_type(TINY))
		return (TINY);
	if (page_size <= size_from_type(SMALL))
		return (SMALL);
	return (LARGE);
}

size_t	get_page_size(size_t size)
{
	size = ft_calculate_page_size(size);
	if (size <= size_from_type(TINY))
		return (size_from_type(TINY));
	if (size <= size_from_type(SMALL))
		return (size_from_type(SMALL));
	return (size);
}
