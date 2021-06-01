//
// Created by ssoraka on 08.10.2020.
//

#include "../includes/malloc.h"

t_page	*new_page(int size)
{
	t_page *page;

	size = ft_get_size(size);
	page = mmap(NULL, size,
			PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (page == FAIL_MMAP)
		return (NULL);
	ft_bzero((void *)page, sizeof(t_page));
	page->size = size;
	page->alloc.empty = size - sizeof(t_page);
	page->alloc.next = NULL;
	return (page);
}

void	insert_page_after_page(t_page *prev, t_page *page)
{
	t_page *next;

	next = prev->next;
	page->next = next;
	if (next)
		next->prev = page;
	prev->next = page;
	page->prev = prev;
}


void	cut_page(t_page *page)
{
	t_page *prev;
	t_page *next;

	next = page->next;
	prev = page->prev;
	prev->next = next;
	if (next)
		next->prev = prev;
	page->next = NULL;
	page->prev = NULL;
}

int		is_empty(t_page *page) {
	return (page->size == page->alloc.empty + sizeof(t_page));
}

int		destroy_page(t_page *page)
{
	return (munmap(page, page->size));
}