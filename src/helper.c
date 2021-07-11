/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

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

void	print_func(char *name, size_t params, void *ptr, size_t size)
{
	if (!get_store()->step)
		return ;
	if (params & START)
		ft_putstr(name);
	if (params & START)
		ft_putstr(" {\n");
	if (params & SIZE)
		ft_putstr(" size=");
	if (params & SIZE)
		ft_putnbr(size);
	if (params & PTR)
		ft_putstr(" ptr=");
	if (params & PTR)
		ft_print_addres(ptr, 1);
	if (params == END)
		ft_putstr("}\n");
	else if (params & END)
		ft_putstr("\n}\n");
	ft_putstr("\n");
}
