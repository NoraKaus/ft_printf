#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t len;

	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

