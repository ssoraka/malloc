//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

void	free_mem_from_page(t_page *page, void *ptr)
{
	t_block *prev;
	t_block *block;
	void *mem;

	prev = &page->alloc;
	while (prev->next) {
		block = prev->next;
		mem = (void *)(block + 1);
		if (mem == ptr)
		{
			prev->next = block->next;
			prev->empty = block->empty + block->used + sizeof(t_block);
			ft_page_to_str(page);
			ft_print_page(page);
			return ;
		}
		prev = prev->next;
	}
}

void	ft_free(void *ptr){
	t_page *page;
	void *end;

	if (!ptr)
		return ;
	page = get_root()->page;
	while(page)
	{
		end = (char *)(page + 1) + page->size;
		if (ptr > page && ptr < end)
		{
			free_mem_from_page(page, ptr);
			return ;
		}
		page = page->next;
	}
}