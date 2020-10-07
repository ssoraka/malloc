//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

#define SYMBOLS "0123456789ABCDEF"

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

void	ft_page_to_str(t_page *page) {

	printf("размер страницы %zu, количество блоков %zu, занято %zu, свободно %zu\n", page->size, page->alloc_count, page->alloc.used, page->alloc.empty);

	t_block *block = page->alloc.next;
	while (block){
		printf("занято %zu, свободно %zu\n", block->used, block->empty);
		block = block->next;
	}
}