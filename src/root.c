//
// Created by ssoraka on 09.10.2020.
//

#include "../includes/malloc.h"

t_root	*get_root()
{
	static t_root root;

	if (!root.is_init)
	{
		root.is_init = 1;
		root.last = &root.page;
	}
	return (&root);
}

t_page	*get_first_page()
{
	return (get_root()->page.next);
}

void	add_page_in_root(t_page *page)
{
	insert_page_after_page(get_root()->last, page);
	get_root()->last = page;
}

void	cut_page_from_root(t_page *page)
{
	t_root *root;

	root = get_root();
	if (root->last == page)
		root->last = page->prev;
	cut_page(page);
}