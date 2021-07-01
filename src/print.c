/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#define MAX_ADDRES_LEN 32
#define HEX 16

char	*ft_color_from_status(t_stat status)
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

void	ft_print_char(unsigned char chr, t_stat is_mem)
{
	if (is_mem != FREE)
		ft_putstr(ft_color_from_status(is_mem));
	ft_putchar(SYMBOLS[chr / 16]);
	ft_putchar(SYMBOLS[chr % 16]);
	if (is_mem != FREE)
		ft_putstr("\033[00m");
	ft_putchar(' ');
}

t_stat	is_mem(void *ptr, t_page *page)
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

void	ft_print_addres(void *ptr, int fd)
{
	char	temp[MAX_ADDRES_LEN];
	size_t	i;
	size_t	addr;

	addr = *((size_t *)&ptr);
	i = 0;
	while (addr != 0 || i == 0)
	{
		temp[i] = SYMBOLS[addr % HEX];
		addr = addr / HEX;
		i++;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	temp[i] = '\0';
	ft_strrevers(temp);
	ft_putstr_fd(temp, fd);
}
