#include "ft_printf.h"

void	assign(t_list *point)
{
	point->null = 0;
	point->number_zeros = 0;
	point->minus = 0;
	point->width = 0;
	point->prec2 = 0;
	point->precision = 0;
	point->type = 0;
	point->chAr = 0;
	point->content = 0;
	point->length = 0;
	point->negative = 0;
	point->not_yet = 0;
}

int	ft_write(char *str2, char *str, int lst)
{
	int			len;
	static int	simbols;
	int			return1;

	len = str - str2;
	if (len)
		write(1, str2, len);
	simbols += len;
	if (lst)
	{
		return1 = simbols;
		simbols = 0;
		return (return1);
	}
	return (simbols);
}

static void	ft_read(va_list *args, char *str)
{
	char	*str2;
	int		pas;

	str2 = str;
	pas = 0;
	while (*str)
	{
		if (*str == '%' && ft_strlen(str) != 1)
		{
			ft_write(str2, str++, 0);
			parser(args, &str);
			str++;
			pas = 0;
			if (*str)
				str2 = str;
		}
		else
		{
			str++;
			pas = 1;
		}
	}
	if (pas)
		ft_write(str2, str, 0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_read(&args, (char *)str);
	va_end(args);
	return (ft_write((char *)str, (char *)str, 1));
}
