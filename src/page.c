//
// Created by ssoraka on 08.10.2020.
//

#include "../includes/malloc.h"

size_t	ft_get_memory_size_on_page(t_page *page)
{
	return (page->size - sizeof(t_page) - sizeof(t_block));
}

size_t	ft_get_size(size_t size)
{
	size += sizeof(t_page);
	if (size <= 128)
		return (128);
	if (size <= 256)
		return (256);
	return (size);
}

t_page	*new_page(int size)
{
	t_page *page;

	size = ft_get_size(size);
	page = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!page)
		return (NULL);
	ft_bzero((void *)page, sizeof(t_page));
	page->size = size;
	page->alloc.empty = size - sizeof(t_page);
	page->alloc.next = NULL;
	return (page);
}

void	destroy_page(t_page *page)
{

}