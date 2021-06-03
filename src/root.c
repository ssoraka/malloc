//
// Created by ssoraka on 09.10.2020.
//

#include "../includes/malloc.h"

t_root	*get_root()
{
	static t_root root;

	if (!root.is_init)
	{
		root.page.next = &root.page;
		root.page.prev = &root.page;
		root.is_init = 1;
	}
	return (&root);
}

t_page	*get_first_page()
{
	return (get_root()->page.next);
}

void	add_page_in_root(t_page *page)
{
	insert_page_after_page(get_root()->page.prev, page);
}

void	cut_page_from_root(t_page *page)
{
	cut_page(page);
}

int		not_end(t_page *page)
{
	return (page != &get_root()->page);
}