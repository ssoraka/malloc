//
// Created by ssoraka on 08.10.2020.
//

#include "../includes/malloc.h"

#define ADDRES_LEN 18

void	ft_print_addres(void *ptr)
{
	char	temp[ADDRES_LEN];
	size_t	i;
	size_t	addr;

	addr = *((size_t *)&ptr);
	i = 0;
	while (addr != 0 || i == 0)
	{
		temp[i] = SYMBOLS[addr % 16];
		addr = addr / 16;
		i++;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	temp[i] = '\0';
	ft_strrevers(temp);
	ft_putstr(temp);
}

void	print_first_string(t_page *page)
{
	if (page->size < getpagesize() * TINY_SIZE)
		ft_putstr("TINY  : ");
	else if (page->size < getpagesize() * SMALL_SIZE)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_print_addres(page);
	ft_putstr("\n");
}

void	print_block_info(t_block *block)
{
	ft_print_addres((void *)(block + 1));
	ft_putstr(" - ");
	ft_print_addres((void *)((char *)(block + 1) + block->used));
	ft_putstr(" : ");
	ft_putnbr(block->used);
	ft_putstr(" bytes\n");
}

void	print_total(size_t total)
{
	ft_putstr("TOTAL : ");
	ft_putnbr(total);
	ft_putstr(" bytes\n");
}

void	show_alloc_mem()
{
	t_page *page;
	t_block *block;
	size_t total;

	total = 0;
	page = get_first_page();
	while(not_end(page))
	{
		print_first_string(page);
		block = page->alloc.next;
		while (block)
		{
			print_block_info(block);
			total += block->used;
			block = block->next;
		}
		page = page->next;
	}
	print_total(total);
}
