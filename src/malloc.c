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

#include "../includes/malloc.h"

t_block	*find_empty_space_on_page(t_page *page, size_t size)
{
	t_block	*block;
	size_t	new_block_size;
	size_t	empty_space;

	block = &page->alloc;
	new_block_size = calculate_block_size(size);
	while (block)
	{
		empty_space = block->empty - get_floor(block->used, sizeof(int));
		if (empty_space >= new_block_size)
			break ;
		block = block->next;
	}
	return (block);
}

void	*alloc_mem(t_page *page, t_block *prev, size_t size)
{
	t_block	*block;
	void	*ptr;
	size_t	floor;

	page->alloc_count++;
	floor = get_floor(prev->used, sizeof(int));
	block = (t_block *)((char *)(prev + 1) + prev->used + floor);
	block->next = prev->next;
	prev->next = block;
	block->used = size;
	block->empty = prev->empty - floor - size - sizeof(t_block);
	prev->empty = floor;
	ptr = (void *)(++block);
	ft_memset(ptr, 'X', size);
	return (ptr);
}

void	*try_alloc_in_used_memory(size_t size)
{
	t_page	*page;
	t_block	*block;
	t_type type;

	type = type_from_alloc_size(size);
	page = get_start_page(USED);
	while (!is_end(page, USED))
	{
		if (type == type_from_page_size(page->size)
				&& page->size >= get_page_size_from_alloc(size)
				&& !is_null(find_empty_space_on_page(page, size), (void **)&block))
			return (alloc_mem(page, block, size));
		page = next_page(page);
	}
	return (NULL);
}

void	*ft_malloc(size_t size)
{
	t_page	*page;
	void	*ptr;

	if (!is_null(try_alloc_in_used_memory(size), &ptr))
		return (ptr);
	if (is_null(get_page_from_store(size), (void **)&page)
		&& is_null(new_page(size), (void **)&page))
		return (NULL);
	insert_page(page, USED);
	ptr = alloc_mem(page, &page->alloc, size);
	return (ptr);
}

/*
 * todo надо изменить все так, чтоб
 */