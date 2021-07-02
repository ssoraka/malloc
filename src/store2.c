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

t_store			g_store = {.is_init = 0};

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
