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
	store->is_init = 1;
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
