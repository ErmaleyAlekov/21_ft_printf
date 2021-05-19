#include "ft_printf.h"

static void	int_to_string(t_list *point, unsigned long long con,
			char *base, char *str)
{
	long long	length;
	char		digit;
	char		*str2;

	str2 = str;
	length = (long long) ft_strlen(base);
	if (con == 0)
		*str = '0';
	while (con != 0)
	{
		digit = base[con % length];
		*(str++) = digit;
		con = con / length;
	}
	if (point->type == 'p')
		ft_strlcat(str, "x0", 20);
	if (point->type == 'p' && con == 0 && point->prec2)
	{
		*str = 0;
		ft_strlcat(str, "x0", 20);
	}
	ft_revers(str2);
	point->content = str2;
	point->length = ft_strlen(str2);
}

void	chars(t_list *point, va_list *args)
{
	if (ft_strchr("c%", point->type))
	{
		if (point->type == 'c')
			point->chAr = va_arg(*args, int);
		else
			point->chAr = '%';
		point->length = 1;
	}
	else if (point->type == 's')
	{
		(point->content) = va_arg(*args, char *);
		if (!(point->content))
			point->length = ft_strlen("(null)");
		else
			point->length = ft_strlen(point->content);
	}
}

static	void	num_cases(t_list *point, long long number, char *ale)
{
	if (number < 0)
	{
		if (!ft_strchr("uxX", point->type))
		{
			point->negative = 1;
			number *= -1;
		}
		else
			number = 4294967295 + number + 1;
	}
	if (!number && point->prec2 && !point->precision)
		return ;
	if (ft_strchr("diu", point->type))
		int_to_string(point, number, "0123456789", ale);
	else
	{
		int_to_string(point, number, "0123456789abcdef", ale);
		if (point->type == 'X')
			ft_toupper(point->content);
	}
}

void	integers(t_list *point, va_list *args, char *ale)
{
	long long		prov_number;

	ft_bzero(ale, 20);
	if (ft_strchr("diuxX", point->type))
	{
		prov_number = va_arg(*args, int);
		num_cases(point, prov_number, ale);
	}
	else
	{
		prov_number = va_arg(*args, unsigned long long int);
		int_to_string(point, prov_number, "0123456789abcdef", ale);
	}
}
