/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

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
		ft_print_char((unsigned char)i, FREE);
	ft_putstr("\n");
}

void	ft_print_page_lines(t_page *page, char *chr, int count)
{
	int	i;

	ft_print_addres(chr, 1);
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
	size_t	i;
	char	*chr;
	size_t	count;

	ft_print_page_header(page);
	chr = (char *)(page);
	i = 0;
	while (i < page->size)
	{
		count = BYTES_IN_LINE;
		if (i + BYTES_IN_LINE > page->size)
			count = page->size % BYTES_IN_LINE + 1;
		ft_print_page_lines(page, chr + i, count);
		i += BYTES_IN_LINE;
	}
	ft_putstr("\n");
}

void	ft_print_mem(void)
{
	t_page	*page;

	pthread_mutex_lock(get_mutex());
	page = get_start_page(USED);
	if (is_end(page, USED))
		ft_putstr("Where is no used memory\n");
	while (!is_end(page, USED))
	{
		ft_print_page(page);
		page = next_page(page);
	}
	pthread_mutex_unlock(get_mutex());
}

void	ft_memset2(void *s, char *chr, size_t n)
{
	size_t	i;
	char	*str;
	int		len;

	len = ft_strlen(chr);
	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = chr[i % len];
		i++;
	}
}

void	*debug(t_page *page, void *ptr, size_t size, size_t params)
{
	if (params & IS_CALLOC)
		ft_bzero(ptr, size);
	if (get_store()->mark)
	{
		if (params & IS_FREE)
			ft_memset2(ptr, FREE_SYMB, size);
		if (params & IS_MALLOC)
			ft_memset2(ptr, MALLOC_SYMB, size);
	}
	if (get_store()->debug)
		ft_print_page(page);
	return (ptr);
}
