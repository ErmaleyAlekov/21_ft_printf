/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/04/19 12:56:53 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*source;
	size_t	i;

	i = 0;
	if (n == 0)
		return (s);
	source = (char *)s;
	while (i < n)
	{
		source[i++] = c;
	}
	return (source);
}
/*Funktsiya memset zapisyvayet kol baytov znacheniya 
C (preobrazovannykh v simvol bez znaka) v stroku S.*/