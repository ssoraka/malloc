//
// Created by ssoraka on 09.10.2020.
//

#include "../includes/malloc.h"

t_pages	*pages_by_type(int type)
{
	return (&(get_store()->p[type]));
}

t_page	*get_start_page(int type)
{
	return (pages_by_type(type)->page.next);
}

int		is_end(t_page *page, int type)
{
	return (page == &pages_by_type(type)->page);
}

void	insert_start_page(t_page *page, int type)
{
	insert_page_after_page(pages_by_type(type)->page.prev, page);
}