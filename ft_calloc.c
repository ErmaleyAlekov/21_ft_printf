/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/04/18 17:01:47 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ale;
	unsigned int	summa;
	unsigned int	i;

	summa = count * size;
	ale = malloc(summa);
	i = 0;
	if (!ale)
		return (0);
	while (summa--)
		ale[i++] = 0;
	return ((void *)ale);
}
/* function allocate memory*/