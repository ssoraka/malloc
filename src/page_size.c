//
// Created by Suzette Soraka on 10/10/20.
//

#include "../includes/malloc.h"

int		size_from_type(int type)
{
//	if (type == TINY)
//		return (getpagesize() * TINY_SIZE);
//	if (type == SMALL)
//		return (getpagesize() * SMALL_SIZE);
	if (type == TINY)
		return (128);
	if (type == SMALL)
		return (256);
	return (0);
}

int		type_from_size(size_t size)
{
	if (size <= size_from_type(TINY))
		return (TINY);
	if (size <= size_from_type(SMALL))
		return (SMALL);
	return (LARGE);
}

size_t	ft_get_size(size_t size)
{
	size += sizeof(t_page) + sizeof(t_block);
	if (size <= size_from_type(TINY))
		return (size_from_type(TINY));
	if (size <= size_from_type(SMALL))
		return (size_from_type(SMALL));
	return (size);
}