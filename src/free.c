//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

void	free_next_block(t_block *block)
{
	t_block *next;

	next = block->next;
	block->next = next->next;
	block->empty = next->empty + next->used + sizeof(t_block);
}

t_block	*get_prev_block_from_page(t_page *page, void *ptr)
{
	t_block *prev;
	t_block *block;
	void *mem;

	prev = &page->alloc;
	while (prev->next) {
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
	t_page *page;
	void *end;

	page = get_root()->page;
	while(page)
	{
		end = (char *)(page + 1) + page->size;
		if (ptr > (void *)page && ptr < end)
			return (page);
		page = page->next;
	}
	return (NULL);
}

t_block *get_prev_block_in_mem(void *ptr)
{
	t_page *page;
	t_block *block;

	if (!ptr)
		return (NULL);
	if (!(page = get_page_with_mem(ptr)))
		return (NULL);
	if (!(block = get_prev_block_from_page(page, ptr)))
		return (NULL);
	return (block);
}

void	ft_free(void *ptr){
	t_block *block;

	if (!(block = get_prev_block_in_mem(ptr)))
		return ;
	free_next_block(block);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_block *block;
	t_block *alloc;

	if (!(block = get_prev_block_in_mem(ptr)))
		return (NULL);
	alloc = block->next;
	if (alloc->used + alloc->empty > size)
	{
		alloc->empty = alloc->used + alloc->empty - size;
		alloc->used = size;
		return ((void *)(++alloc));
	}
	else
		free_next_block(block);
	return (ft_malloc(size));
}