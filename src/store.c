/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

#define PAGE_COUNT 2
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
t_store			g_store = {.is_init = 0};

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

	type = type_from_page_size(page->size);
	insert_page(page, type);
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

	ft_bzero(store, sizeof(t_store));
	pages = store->p;
	i = 0;
	while (i < TYPE_COUNT)
	{
		pages->page.next = &pages->page;
		pages->page.prev = &pages->page;
		pages++;
		i++;
	}
}
