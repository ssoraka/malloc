//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

char	*ft_color_from_status(int status)
{
	if (status == BLOCK)
		return ("\033[0;32m");
	if (status == ALLOC)
		return ("\033[7;37m");
	if (status == PAGE)
		return ("\033[0;31m");
	if (status == NUM)
		return ("\033[0;30m");
	return ("\033[00m");
}

void	ft_print_char(unsigned char chr, int is_mem)
{
	if (is_mem != FREE)
		ft_putstr(ft_color_from_status(is_mem));
	ft_putchar(SYMBOLS[chr / 16]);
	ft_putchar(SYMBOLS[chr % 16]);
	if (is_mem != FREE)
		ft_putstr("\033[00m");
	ft_putchar(' ');
}

int	is_mem(void *ptr, t_page *page)
{
	t_block	*block;
	void	*start;
	void	*end;

	if (ptr < (void *)(page + 1))
		return (PAGE);
	block = page->alloc.next;
	while (block)
	{
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

void	ft_print_chars(char *ptr, int count)
{
	int	i;

	ft_putchar('|');
	i = 0;
	while (i < BYTES_IN_LINE)
	{
		if (i > count)
			ft_putchar(' ');
		else if (ft_isprint(ptr[i]))
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}

void	ft_print_page_header(t_page *page)
{
	int		i;
	size_t	l;

	l = *((long *)&page);
	while (l > 0)
	{
		ft_putstr(" ");
		l = l >> 4;
	}
	ft_putstr("    ");
	i = -1;
	while (++i < BYTES_IN_LINE)
		ft_print_char((unsigned char)i, NUM);
	ft_putstr("\n");
}

void	ft_print_page_lines(t_page *page, char *chr, int count)
{
	int	i;

	ft_print_addres(chr);
	ft_putstr("  ");
	i = -1;
	while (++i < count)
		ft_print_char(chr[i], is_mem(chr + i, page));
	while (++i <= BYTES_IN_LINE)
		ft_putstr("   ");
	ft_print_chars(chr, count);
	ft_putstr("\n");
}

void	ft_print_page(t_page *page)
{
	int		i;
	char	*chr;
	int		count;

	ft_print_page_header(page);
	chr = (char *)(page);
	i = 0;
	while (i < page->size)
	{
		count = BYTES_IN_LINE;
		if (i + BYTES_IN_LINE > page->size)
			count = page->size % BYTES_IN_LINE;
		ft_print_page_lines(page, chr + i, count);
		i += BYTES_IN_LINE;
	}
	ft_putstr("\n");
}

void	ft_print_mem(void)
{
	t_page	*page;

	page = get_start_page(USED);
	if (is_end(page, USED))
		ft_putstr("Where is no used memory\n");
	while (!is_end(page, USED))
	{
		ft_print_page(page);
		page = next_page(page);
	}
}
