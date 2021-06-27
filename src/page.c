/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page	*new_page(size_t size)
{
	t_page	*page;

	size = get_page_size_from_alloc(size);
	page = mmap(NULL, size,
			PROT_READ | PROT_WRITE | PROT_EXEC,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (page == (void *)FAIL_MMAP)
		return (NULL);
	ft_bzero((void *)page, sizeof(t_page));
	page->size = size;
	page->alloc.empty = size - sizeof(t_page);
	page->alloc.next = NULL;
	return (page);
}

void	insert_page_after_page(t_page *prev, t_page *page)
{
	t_page	*next;

	next = prev->next;
	page->next = next;
	prev->next = page;
	page->prev = prev;
	next->prev = page;
}

void	cut_page(t_page *page)
{
	t_page	*prev;
	t_page	*next;

	next = page->next;
	prev = page->prev;
	prev->next = next;
	next->prev = prev;
	page->next = NULL;
	page->prev = NULL;
}

int	destroy_page(t_page *page)
{
	return (munmap(page, page->size));
}

t_page	*next_page(t_page *page)
{
	return (page->next);
}
