/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#define FREE_ERROR1 "malloc: *** error for object "
#define FREE_ERROR2 ": pointer being freed was not allocated\n"
#define REALLOC_ERROR2 ": pointer being realloc'd was not allocated\n"

void	free_next_block(t_page *page, t_block *block, size_t params)
{
	t_block	*next;

	next = block->next;
	block->next = next->next;
	block->empty += next->empty + next->used + sizeof(t_block);
	page->alloc_count--;
	debug(page, (void *)(block + 1), next->used, params);
}

t_block	*get_prev_block_from_page(t_page *page, void *ptr)
{
	t_block	*prev;
	t_block	*block;
	void	*mem;

	if (!page || !ptr)
		return (NULL);
	prev = &page->alloc;
	while (prev->next)
	{
		block = prev->next;
		mem = (void *)(block + 1);
		if (mem == ptr)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

t_page	*get_page_with_mem(void *ptr)
{
	t_page	*page;
	void	*end;

	if (!ptr)
		return (NULL);
	page = get_start_page(USED);
	while (!is_end(page, USED))
	{
		end = (char *)(page + 1) + page->size;
		if (ptr > (void *)page && ptr < end)
			return (page);
		page = next_page(page);
	}
	return (NULL);
}

void	ft_free(void *ptr)
{
	t_page	*page;
	t_block	*block;

	page = get_page_with_mem(ptr);
	block = get_prev_block_from_page(page, ptr);
	if (!page || !block)
		exit_with_error(ptr, FREE_ERROR1, FREE_ERROR2);
	free_next_block(page, block, IS_FREE);
	if (!page->alloc_count)
	{
		cut_page(page);
		store_page(page);
	}
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_page	*page;
	t_block	*block;
	t_block	*alloc;
	void	*new_alloc;

	page = get_page_with_mem(ptr);
	block = get_prev_block_from_page(page, ptr);
	if (!block)
		exit_with_error(ptr, FREE_ERROR1, REALLOC_ERROR2);
	alloc = block->next;
	if (type_from_alloc_size(size) == type_from_page_size(page->size)
		&& alloc->used + alloc->empty >= size)
	{
		alloc->empty = alloc->used + alloc->empty - size;
		alloc->used = size;
		return (debug(page, ptr, size, IS_MALLOC));
	}
	new_alloc = ft_malloc(size, NO_PARAMS);
	if (!new_alloc)
		return (NULL);
	size = (size < alloc->used) * size + (size >= alloc->used) * alloc->used;
	ft_memcpy(new_alloc, ptr, size);
	free_next_block(page, block, IS_FREE);
	return (debug(page, new_alloc, size, IS_MALLOC));
}
