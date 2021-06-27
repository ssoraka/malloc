/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#define FREE_ERROR1 "malloc: *** error for object "
#define FREE_ERROR2 ": pointer being freed was not allocated\n"

void	free_next_block(t_page *page, t_block *block)
{
	t_block	*next;

	next = block->next;
	block->next = next->next;
	block->empty += next->empty + next->used + sizeof(t_block);
	page->alloc_count--;
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
	{
		ft_putstr_fd(FREE_ERROR1, 2);
		ft_print_addres(ptr, 2);
		ft_putstr_fd(FREE_ERROR2, 2);
		free_store();
		exit(134);
	}
	free_next_block(page, block);
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
		return (NULL);
	alloc = block->next;
	if (type_from_size(get_page_size(size)) == type_from_size(page->size)
			&& alloc->used + alloc->empty >= size)
	{
		alloc->empty = alloc->used + alloc->empty - size;
		alloc->used = size;
		return (ptr);
	}
	new_alloc = ft_malloc(size);
	if (!new_alloc)
		return (NULL);
	size = (size < alloc->used) ? size : alloc->used;
	ft_memcpy(new_alloc, ptr, size);
	free_next_block(page, block);
	return (new_alloc);
}
