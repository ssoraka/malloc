//
// Created by ssoraka on 07.10.2020.
//

#include "../includes/malloc.h"

void	ft_memset(void *s, size_t n, char chr)
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

void	ft_putchar(int chr) {
	write(1, (void *)&chr, 1);
}

void	ft_putstr(char *str) {
	while (*str) {
		ft_putchar(*str);
		str++;
	}
}