/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

#define ADDRES_LEN 18

void	ft_print_addres(void *ptr, int fd)
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
	ft_putstr_fd(temp, fd);
}

void	print_first_string(t_page *page)
{
	if (page->size < (size_t)getpagesize() * TINY_SIZE)
		ft_putstr("TINY  : ");
	else if (page->size < (size_t)getpagesize() * SMALL_SIZE)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_print_addres(page, 1);
	ft_putstr("\n");
}

void	print_block_info(t_block *block)
{
	ft_print_addres((void *)(block + 1), 1);
	ft_putstr(" - ");
	ft_print_addres((void *)((char *)(block + 1) + block->used), 1);
	ft_putstr(" : ");
	ft_putnbr_fd(block->used, 1);
	ft_putstr(" bytes\n");
}

void	print_total(size_t total)
{
	ft_putstr("TOTAL : ");
	ft_putnbr_fd(total, 1);
	ft_putstr(" bytes\n");
}

void	show_alloc_mem(void)
{
	t_page	*page;
	t_block	*block;
	size_t	total;

	lock();
	total = 0;
	page = get_start_page(USED);
	while (!is_end(page, USED))
	{
		print_first_string(page);
		block = page->alloc.next;
		while (block)
		{
			print_block_info(block);
			total += block->used;
			block = block->next;
		}
		page = next_page(page);
	}
	print_total(total);
	unlock(NULL);
}
