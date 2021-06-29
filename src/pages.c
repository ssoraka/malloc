/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_pages	*pages_by_type(t_type type)
{
	return (&(get_store()->p[type]));
}

t_page	*get_start_page(t_type type)
{
	return (pages_by_type(type)->page.next);
}

int	is_end(t_page *page, t_type type)
{
	return (page == &pages_by_type(type)->page);
}

void	insert_page(t_page *page, t_type type)
{
	t_page *prev;

	prev = &pages_by_type(type)->page;
	while (!is_end(prev->next, type))
	{
		if (page < prev->next)
		{
			insert_page_after_page(prev, page);
			return ;
		}
		prev = next_page(prev);
	}
	insert_page_after_page(pages_by_type(type)->page.prev, page);
}
