#include "ft_printf.h"

ssize_t	handle_text(va_list *list, t_flags *flags)
{
	ssize_t	total;
	ssize_t	width;
    ssize_t chck;

	total = 0;
    chck = 0;
	width = get_width(flags) - 1;
	if (width > 0 && !flags->minus)
	{
		if(add_pad(width, ' ', &total) < 0)
			return (-1);
	}
	if (flags->type == 'c')
		chck = ft_putchar(va_arg(*list, int));
	else if (flags->type == '%')
		chck = ft_putchar('%');
    if (chck < 0)
		return (-1);
	if (flags->minus)
	{
		if(add_pad(width, ' ', &total) < 0)
			return (-1);
	}
	return (total + chck);
}

ssize_t		handle_string(va_list *list, t_flags *flags)
{	
	ssize_t	prec;
	ssize_t	width;
	ssize_t	total;
	char *str;

	total = 0;
	str = va_arg(*list, char *);
	if (!str)
    {
        str = "(null)";
        if (flags->precision != -1 && flags->precision < 6)
            str = "";
    }
	prec = get_str_len(flags, str);
	width = get_width(flags) - prec;
	if (width > 0 && !flags->minus)
	{
		if(add_pad(width, ' ', &total) < 0)
			return (-1);
	}
	if(add_str(str, prec, &total) < 0)
		return (-1);
	if (flags->minus)
	{
		if(add_pad(width, ' ', &total) < 0)
			return (-1);
	}
	return (total);
}