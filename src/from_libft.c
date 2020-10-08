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

void	ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	while (n-- > 0)
		*(dest++) = *(source++);
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

size_t		ft_strlen(const char *str)
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

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar('2');
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}