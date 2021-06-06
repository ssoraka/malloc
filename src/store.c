//
// Created by ssoraka on 08.10.2020.
//

#include "../includes/malloc.h"

#define PAGE_COUNT 2

void	free_store(void)
{
	t_page	*page;
	int		type;

	type = 0;
	while (type < TYPE_COUNT)
	{
		page = get_start_page(type);
		while (!is_end(page, type))
		{
			cut_page(page);
			destroy_page(page);
			page = get_start_page(type);
		}
		type++;
	}
}

void	store_page(t_page *page)
{
	int	type;

	type = type_from_size(page->size);
	insert_start_page(page, type);
}

t_page	*get_page_from_store(size_t size)
{
	t_page	*page;
	int		type;

	size = ft_get_size(size);
	type = type_from_size(size);
	page = get_start_page(type);
	if (is_end(page, type))
		return (NULL);
	cut_page(page);
	return (page);
}

int	new_page_by_type(int type)
{
	t_page	*page;

	page = new_page(size_from_type(type) - sizeof(t_page) - sizeof(t_block));
	if (!page)
		return (0);
	store_page(page);
	return (1);
}

int	fill_store(void)
{
	int		i;

	i = 0;
	while (i < PAGE_COUNT)
	{
		if (!new_page_by_type(TINY)
			|| !new_page_by_type(SMALL))
		{
			free_store();
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_store(t_store *store)
{
	t_pages	*pages;
	int		i;

	pages = store->p;
	i = 0;
	while (i < TYPE_COUNT)
	{
		pages->page.next = &pages->page;
		pages->page.prev = &pages->page;
		pages++;
		i++;
	}
	store->is_init = 1;
}

t_store	*get_store(void)
{
	static t_store	store;

	if (!store.is_init)
	{
		init_store(&store);
		if (!fill_store())
			return (NULL);
	}
	return (&store);
}

void	print_parameters(int type)
{
	if (type == TINY)
		ft_putstr("TINY PAGES ");
	else if (type == SMALL)
		ft_putstr("SMALL PAGES ");
	else
		ft_putstr("LARGE PAGES ");
	ft_putnbr_fd(size_from_type(type), 1);
	ft_putstr("\n");
}

void	print_store(void)
{
	t_page	*page;
	int		type;

	type = 0;
	while (type < STORE_COUNT)
	{
		page = get_start_page(type);
		if (!is_end(page, type))
			print_parameters(type);
		while (!is_end(page, type))
		{
			ft_print_page(page);
			page = next_page(page);
		}
		type++;
	}
}
