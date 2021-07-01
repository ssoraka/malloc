/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_page	*get_page_from_store(size_t size)
{
	t_page	*page;
	int		type;

	type = type_from_alloc_size(size);
	page = get_start_page(type);
	if (is_end(page, type))
		return (NULL);
	cut_page(page);
	return (page);
}

t_store	*get_store(void)
{
	if (!g_store.is_init)
	{
		init_store(&g_store);
		if (!fill_store())
			return (NULL);
	}
	return (&g_store);
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
