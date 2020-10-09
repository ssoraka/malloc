//
// Created by Suzette Soraka on 10/4/20.
//

#include "../includes/malloc.h"

/*
 * так, я начал неправильно
 * нужно сначала попытаться вставить в последний кадр новый блок памяти
 * далее проверить все предыдущие
 * далее доставать из хранилища выделенные блоки памяти
 * далее создавать
 *
 * при освобождении блоки возвращать в хранилище
 *
 * в каждом кадре храним список ссылок на выделенную память
 * для этих списков нужны свои кадры
 * но их уже не нужно жестко контролировать.
 * всю запись вести в обратном порядке, добавлять только в начало списка
 *
 * надо навставлять заглушек, вместо выделения памяти
 * и отладить все изолированно
 */


t_block	*find_empty_space_on_page(t_page *page, size_t size)
{
	t_block *block;

	block = &page->alloc;
	size += sizeof(t_block);
	while(block)
	{
		if (block->empty >= size)
			break ;
		block = block->next;
	}
	return (block);
}

void	*alloc_mem(t_page *page, t_block *prev, size_t size)
{
	t_block *block;
	void *ptr;

	page->alloc_count++;
	block = (t_block *)((char *)(prev + 1) + prev->used) ;
	block->next = prev->next;
	prev->next = block;
	block->used = size;
	block->empty = prev->empty - size - sizeof(t_block);
	prev->empty = 0;

	ptr = (void *)(++block);
	ft_memset(ptr, size, ' ');
	return (ptr);
}

void	*try_alloc_in_used_memory(size_t size)
{
	t_page *page;
	t_block *block;

	page = get_first_page();
	while(page)
	{
		if (page->size > size)
			if ((block = find_empty_space_on_page(page, size)))
				return (alloc_mem(page, block, size));
		page = page->next;
	}
	return (NULL);
}



void	*ft_malloc(size_t size)
{
	t_page	*page;
	void	*ptr;

	if (!size)
		return (0);
	if ((ptr = try_alloc_in_used_memory(size)))
		return (ptr);
	//новую страницу надо получать из имеющихся, а только после этого создавать
	if (!(page = new_page(size)))
		return (NULL);
	add_page_in_root(page);
	ptr = alloc_mem(page, &page->alloc, size);
	return (ptr);
}