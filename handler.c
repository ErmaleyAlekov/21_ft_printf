#include "ft_printf.h"

static int	max(int args, ...)
{
	int			i;
	int			v;
	int			current;
	va_list		valist;

	va_start(valist, args);
	i = -1;
	v = 2147483647;
	while (++i < args)
	{
		current = va_arg(valist, int);
		if (v < current || v == 2147483647)
			v = current;
	}
	va_end(valist);
	return (v);
}

static	void	gen_oders(t_list *point)
{
	if (point->type == 's' && point->prec2 && point->precision < point->length)
		point->length = point->precision;
	else if (point->prec2 && point->precision <= point->length)
		point->null = 0;
	else if (!ft_strchr("sc%", point->type) && point->precision > point->length)
		point->number_zeros = max(2, point->precision - point->length, 0);
	if (point->length + point->number_zeros >= point->width)
		point->width = 0;
	else if (point->number_zeros > 0)
		point->width = point->width - point->length - point->number_zeros;
	else
		point->width = point->width - point->length;
	if (point->negative && point->width > 0)
		point->width -= 1;
	if (point->null == 1 && !point->number_zeros && !point->minus)
	{
		point->number_zeros = point->width;
		point->width = 0;
	}
	if (point->minus)
	{
		point->minus = point->width;
		point->width = 0;
	}
}

void	cleans(t_list *point)
{
	if (!point->not_yet)
	{
		if (point->width < 0)
		{
			point->minus = 1;
			point->width *= -1;
		}
		if (point->precision < 0)
		{
			point->prec2 = 0;
			point->precision = 0;
		}
		gen_oders(point);
	}
}

static void	content(t_list *point, char **str2, char **res, int size)
{
	char	*blank;

	blank = "";
	if (point->type == 'c' && !point->chAr)
	{
		ft_write(*str2, *res, 0);
		ft_write(blank, blank + 1, 0);
		ft_bzero(*str2, size);
		*res = *str2;
		point->length = 0;
	}
	else if (point->type == 'c' || point->type == '%')
		ft_memset(*res, point->chAr, 1);
	else if (!point->content && point->type == 's')
		ft_strlcat(*res, "(null)", point->length + 1);
	else
		ft_strlcat(*res, (char *)point->content, point->length + 1);
}

void	buffer(t_list *point)
{
	char	*str2;
	char	*res;
	int		size;

	size = point->width + point->negative + point->number_zeros
		+ point->length + point->minus + 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return ;
	str2 = res;
	while (!point->minus && point->width-- > 0)
		*(res++) = 32;
	if (point->negative)
		ft_memset(res++, 45, 1);
	if (point->number_zeros)
		ft_memset(res, 48, point->number_zeros);
	res += point->number_zeros;
	content(point, &str2, &res, size);
	res += point->length;
	while (point->minus--)
		*(res++) = 32;
	ft_write(str2, res, 0);
	free(str2);
	str2 = 0;
}
