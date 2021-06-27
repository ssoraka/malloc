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

size_t	size_from_type(int type)
{
	if (type == TINY)
		return (256);
	if (type == SMALL)
		return (512);
	return (0);
}

int	type_from_size(size_t size)
{
	if (size <= size_from_type(TINY))
		return (TINY);
	if (size <= size_from_type(SMALL))
		return (SMALL);
	return (LARGE);
}

size_t	ft_round(size_t size, int mod)
{
	return (size + (mod - size % mod) * (size % mod > 0));
}

size_t	ft_get_size(size_t size)
{
	size += sizeof(t_page) + sizeof(t_block);
	size = ft_round(size, sizeof(long));
	if (size <= size_from_type(TINY))
		return (size_from_type(TINY));
	if (size <= size_from_type(SMALL))
		return (size_from_type(SMALL));
	return (size);
}
