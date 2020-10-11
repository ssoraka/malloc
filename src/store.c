//
// Created by ssoraka on 08.10.2020.
//

#include "../includes/malloc.h"

#define PAGE_COUNT 2

void	free_store()
{
	t_store *store;
	t_page *page;
	t_page *tmp;
	int i;

	store = get_store();
	i = 0;
	while (i < TYPE_COUNT)
	{
		page = store->p[i];
		while (page)
		{
			tmp = page;
			page = page->next;
			destroy_page(tmp);
		}
		i++;
	}
}

void	store_page(t_page *page)
{
	t_store *store;
	int i;

	store = get_store();
	i = type_from_size(page->size);
	if (store->size[i] < PAGE_COUNT)
	{
		page->next = store->p[i];
		store->p[i] = page;
		store->size[i]++;
	}
	else
		destroy_page(page);
}

t_page	*get_page_from_store(size_t size)
{
	t_store *store;
	t_page *page;
	int i;

	store = get_store();
	i = type_from_size(size);
	page = store->p[i];
	if (page)
	{
		store->p[i] = page->next;
		page->next = NULL;
	}
	return (page);
}

int		create_new_store(t_store *store)
{
	t_page *page;
	int i;

	ft_bzero(store, sizeof(t_store));
	store->is_init = 1;
	i = 0;
	while (i < PAGE_COUNT)
	{
		if (!(page = new_page(size_from_type(TINY) - sizeof(t_page) - sizeof(t_block))))
		{
			free_store();
			return (0);
		}
		store_page(page);
		if (!(page = new_page(size_from_type(SMALL) - sizeof(t_page) - sizeof(t_block))))
		{
			free_store();
			return (0);
		}
		store_page(page);
		i++;
	}
	return (1);
}


t_store	*get_store()
{
	static t_store store;

	if (!store.is_init)
	{
		if (!create_new_store(&store))
			return (NULL);
	}
	return (&store);
}

void	store_to_string()
{
	t_store *store;
	t_page *page;
	int i;

	store = get_store();
	i = 0;
	while (i < TYPE_COUNT)
	{
		page = store->p[i];
		while (page)
		{
			ft_print_page(page);
			page = page->next;
		}
		i++;
	}
}