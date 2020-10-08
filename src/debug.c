//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

char	*ft_color_from_status(int status){
	if (status == BLOCK)
		return ("\033[0;32m");
	if (status == ALLOC)
		return ("\033[7;37m");
	return ("\033[00m");
}

void	ft_print_char(unsigned char chr, int is_mem) {
	if (is_mem != FREE)
		ft_putstr(ft_color_from_status(is_mem));
	ft_putchar(SYMBOLS[chr / 16]);
	ft_putchar(SYMBOLS[chr % 16]);
	if (is_mem != FREE)
		ft_putstr("\033[00m");
	ft_putchar(' ');
}

int		is_mem(void *ptr, t_block *block)
{
	void *start;
	void *end;

	while (block) {
		start = block + 1;
		end = (char *)start + block->used;
		if (ptr >= (void *)block && ptr < start)
			return (BLOCK);
		if (ptr >= start && ptr < end)
			return (ALLOC);
		block = block->next;
	}
	return (FREE);
}

void	ft_print_page(t_page *page) {
	int i;
	unsigned char *ptr;

	ptr = (unsigned char *)(page + 1);
	i = 0;
	while (i < page->size)
	{
		ft_print_char(ptr[i], is_mem(ptr + i, page->alloc.next));
		if (!((i + 1) % 16))
			ft_putchar('\n');
		i++;
	}
}

/*
 * это надо будет удалить нафиг
 */
void	ft_page_to_str(t_page *page) {

	printf("размер страницы %zu, вес страницы %d, количество блоков %zu, занято %zu, свободно %zu\n", page->size, sizeof(t_page), page->alloc_count, page->alloc.used, page->alloc.empty);

	t_block *block = page->alloc.next;
	while (block){
		printf("размер блока %d, занято %zu, свободно %zu\n", sizeof(t_block), block->used, block->empty);
		block = block->next;
	}
}

void	ft_print_mem() {
	t_page *page;

	page = get_root()->page;
	ft_page_to_str(page);
	while(page) {
		ft_print_page(page);
		page = page->next;
	}
}