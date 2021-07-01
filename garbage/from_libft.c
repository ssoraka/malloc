/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	ft_memset(void *s, int chr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = chr;
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = '\0';
}

void	ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	while (n-- > 0)
		*(dest++) = *(source++);
}

void	ft_putchar_fd(int chr, int fd)
{
	write(fd, (void *)&chr, 1);
}

void	ft_putchar(int chr)
{
	write(1, (void *)&chr, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

void	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (*s)
		s++;
	i = s - str;
	return (i);
}

char	*ft_strrevers(char *str)
{
	int		i;
	int		len;
	char	chr;

	i = 0;
	if (str == NULL || str[0] == 0)
		return (NULL);
	len = ft_strlen(str);
	while (i < len / 2)
	{
		chr = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = chr;
		i++;
	}
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('2', fd);
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	is_null(void *ptr, void **addr)
{
	*addr = ptr;
	return (ptr == NULL);
}
