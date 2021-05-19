#include "ft_printf.h"

static	void	flags(t_list *point, char **str)
{
	while (ft_strchr("0-", **str) && ft_strlen(*str) > 1)
	{
		if (**str == '-')
		{
			point->minus = 1;
			*(str) += 1;
		}
		else if (**str == '0')
		{
			point->null = 1;
			*(str) += 1;
		}
	}
}

static	void	width(t_list *point, char **str, va_list *args)
{
	while (str && (ft_isdigit(**str) || **str == '*'))
	{
		if (**str == '*' && !(point->width))
		{
			point->width = va_arg(*args, int);
			*(str) += 1;
		}
		else if (!point->width)
		{
			while (ft_isdigit(**str))
			{
				point->width = point->width * 10 + (int)**str - '0';
				*(str) += 1;
			}
		}
	}
}

static	void	precision(t_list *point, char **str, va_list *args)
{
	if (str && (**str == '.'))
	{
		if (*(*(str) + 1) == '*' && !point->precision)
		{
			point->precision = va_arg(*args, int);
			point->prec2 = 1;
			*(str) += 2;
		}
		else
		{
			*(str) += 1;
			while (*str && ft_isdigit(**str))
			{
				point->precision = point->precision * 10 + (int)**str - '0';
				*(str) += 1;
			}
			point->prec2 = 1;
		}
		if (!point->prec2)
			*(str) += 1;
	}
}

static	void	type(t_list *point, char **str)
{
	int		i;
	char	*types;

	i = -1;
	types = "cspdiuxX";
	while (types[++i] && str)
	{
		if (**str == types[i] || **str == '%')
		{
			point->type = **str;
			return ;
		}
	}
	point->not_yet = 1;
}

void	parser(va_list *args, char **str)
{
	t_list	point;
	char	*str2;
	char	ale[20];

	str2 = *str;
	assign(&point);
	flags(&point, str);
	width(&point, str, args);
	precision(&point, str, args);
	type(&point, str);
	if (point.not_yet)
		ft_write(str2 - 1, *str, 0);
	else
	{
		if (!point.type)
			point.content = 0;
		else if (ft_strchr("cs%", point.type))
			chars(&point, args);
		else
			integers(&point, args, ale);
		cleans(&point);
		buffer(&point);
	}
}
