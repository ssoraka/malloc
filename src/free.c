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
	page = get_first_page();
	while(page)
	{
		end = (char *)(page + 1) + page->size;
		if (ptr > (void *)page && ptr < end)
			return (page);
		page = page->next;
	}
	return (NULL);
}

void	ft_free(void *ptr){
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
		cut_page_from_root(page);
		store_page(page);
	}

}

void	*ft_realloc(void *old, size_t size)
{
	t_page *page;
	t_block *block;
	t_block *alloc;
	void *ptr;

	size = ft_round(size, sizeof(long));
	page = get_page_with_mem(old);
	if (!(block = get_prev_block_from_page(page, old)))
		return (NULL);
	alloc = block->next;
	if (alloc->used + alloc->empty > size)
	{
		alloc->empty = alloc->used + alloc->empty - size;
		alloc->used = size;
		return ((void *)(++alloc));
	}
	if (!(ptr = ft_malloc(size)))
		return (NULL);
	ft_memcpy(ptr, old, alloc->used);
	free_next_block(page, block);
	return (ptr);
}

void	*ft_calloc(size_t size)
{
	void *ptr;

	size = ft_round(size, sizeof(long));
	if (!(ptr = ft_malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}