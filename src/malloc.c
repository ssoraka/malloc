//
// Created by Suzette Soraka on 10/4/20.
//

#include "../includes/malloc.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = '\0';
}

void	init_pages(t_pages *pages, char *mem, int page_size, int page_count)
{
	int i;
	t_page *page;

	i = 0;
	pages->head = NULL;
	page = (t_page *)mem;
	while (i < page_count)
	{
		ft_bzero((void *)page, sizeof(t_page));
		page->mem = mem + sizeof(t_page);
		page->size = page_size - sizeof(t_page);
		page->next = (t_page *)(mem + page_size);
		page++;
		mem = mem + page_size;
		i++;
	}
	pages->last = page;
	pages->count = page_count;
}

int		ft_get_page_size(int type)
{
	if (type == TINY)
		return (getpagesize() * TINY_SIZE);
	if (type == SMALL)
		return (getpagesize() * SMALL_SIZE);
}

int		type_from_size(int size)
{
	if (size < ft_get_page_size(TINY))
		return (TINY);
	if (size < ft_get_page_size(SMALL))
		return (SMALL);
	return (LARGE);
}


t_store		*create_new_store()
{
	t_store	*mem;
	int size;
	int tiny_size;
	int small_size;

	tiny_size = (ft_get_page_size(TINY) + sizeof(t_page)) * 100;
	small_size = (ft_get_page_size(SMALL) + sizeof(t_page)) * 100;
	size = sizeof(t_store) + tiny_size + small_size;
	mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!mem)
		return (NULL);
	init_pages(&mem->p[TINY], (char *)(mem + 1),
				TINY_SIZE + sizeof(t_page), 100);
	init_pages(&mem->p[SMALL], (char *)(mem + 1) + tiny_size,
				SMALL_SIZE + sizeof(t_page), 100);
	mem->p[LARGE] = (t_pages){NULL, NULL, 0};
	return (mem);
}


t_store		*get_store()
{
	static t_store	*mem;

	if (!mem)
		mem = create_new_store();
	return (mem);
}

t_page *find_page(t_pages *pages, size_t size)
{
	t_page *page;
	int i;

	page = pages->head;
	i = 0;
	while (i < pages->count && page) {
		if (page->size - page->used > size)
			return (page);
		page = page->next;
		i++;
	}
	return (insert_new_page(pages, ));
}


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

void	*ft_malloc(size_t size)
{
	t_pages *pages;
	t_store	*store;
	void *ptr;

	size += sizeof(t_page);
	store = get_store();
	if (!store)
		return (NULL);
	pages = &store->p[type_from_size(size)];
	ptr = find_page(pages, size);
	if (!ptr)
		return (NULL);



	return (NULL);
}