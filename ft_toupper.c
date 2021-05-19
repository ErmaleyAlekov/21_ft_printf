#include "ft_printf.h"

static int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	ft_toupper(char *str)
{
	while (str && *str)
	{
		*str = toupper(*str);
		str++;
	}
}
