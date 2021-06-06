//
// Created by Suzette Soraka on 10/4/20.
//

#include "../includes/malloc.h"

t_block	*find_empty_space_on_page(t_page *page, size_t size)
{
	t_block	*block;

	block = &page->alloc;
	size += sizeof(t_block);
	while (block)
	{
		if (block->empty >= size)
			break ;
		block = block->next;
	}
	return (block);
}

void	*alloc_mem(t_page *page, t_block *prev, size_t size)
{
	t_block	*block;
	void	*ptr;

	page->alloc_count++;
	block = (t_block *)((char *)(prev + 1) + prev->used);
	block->next = prev->next;
	prev->next = block;
	block->used = size;
	block->empty = prev->empty - size - sizeof(t_block);
	prev->empty = 0;
	ptr = (void *)(++block);
	ft_memset(ptr, size, 'X');
	return (ptr);
}

void	*try_alloc_in_used_memory(size_t size)
{
	t_page	*page;
	t_block	*block;

	page = get_start_page(USED);
	while (!is_end(page, USED))
	{
		if (page->size > size)
			if (!is_null(find_empty_space_on_page(page, size), (void **)&block))
				return (alloc_mem(page, block, size));
		page = next_page(page);
	}
	return (NULL);
}

void	*malloc1(size_t size)
{
	t_page	*page;
	void	*ptr;

	if (!size)
		return (0);
	size = ft_round(size, sizeof(long));
	if (!is_null(try_alloc_in_used_memory(size), &ptr))
		return (ptr);
	if (is_null(get_page_from_store(size), (void **)&page)
		&& is_null(new_page(size), (void **)&page))
		return (NULL);
	insert_start_page(page, USED);
	ptr = alloc_mem(page, &page->alloc, size);
	return (ptr);
}
