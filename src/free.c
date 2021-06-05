//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

void	free_next_block(t_page *page, t_block *block)
{
	t_block *next;

	next = block->next;
	block->next = next->next;
	block->empty += next->empty + next->used + sizeof(t_block);
	page->alloc_count--;
}

t_block	*get_prev_block_from_page(t_page *page, void *ptr)
{
	t_block *prev;
	t_block *block;
	void *mem;

	if (!page || !ptr)
		return (NULL);
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

void	free(void *ptr){
	t_page *page;
	t_block *block;

	if (!(page = get_page_with_mem(ptr))
	|| !(block = get_prev_block_from_page(page, ptr)))
	{
		/*TODO надо сделать ошибку освобождения неаллоцированной памяти*/
		return;
	}
	free_next_block(page, block);
	/*TODO проверить работоспособность*/
	if (!page->alloc_count)
	{
		cut_page(page);
		store_page(page);
	}

}

void	*realloc(void *ptr, size_t size)
{
	t_page *page;
	t_block *block;
	t_block *alloc;

	size = ft_round(size, sizeof(long));
	page = get_page_with_mem(ptr);
	if (!(block = get_prev_block_from_page(page, ptr)))
		return (NULL);
	alloc = block->next;
	if (alloc->used + alloc->empty > size)
	{
		alloc->empty = alloc->used + alloc->empty - size;
		alloc->used = size;
		return ((void *)(++alloc));
	}
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_memcpy(ptr, ptr, alloc->used);
	free_next_block(page, block);
	return (ptr);
}

void	*calloc(size_t count, size_t size)
{
	void *ptr;

	size = ft_round(size * count, sizeof(long));
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}