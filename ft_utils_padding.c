#include "ft_printf.h"

ssize_t add_pad(ssize_t len, char c, ssize_t *total)
{
    ssize_t chck;
    
    if (len <= 0)
        return (0);
    chck = put_loop(len, c);
    if (chck < 0)
        return (-1);
    *total += chck;
    return (1);
}

ssize_t	get_str_len(t_flags *flags, char *str)
{
	ssize_t prec;
	ssize_t len;

	prec = get_precision(flags);
	len = ft_strlen(str);
	if (prec !=  -1 && prec < len)
        return (prec);
	return (len);
}

ssize_t	add_str(char *str, ssize_t len, ssize_t *total)
{
    ssize_t chck;
    
    if (len <= 0)
        return (0);
    chck = ft_putstr(str, len);
    if (chck < 0)
        return (-1);
    *total += chck;
    return (1);
}