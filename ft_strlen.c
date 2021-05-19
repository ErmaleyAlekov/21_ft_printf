/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/04/18 15:37:36 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (str)
		while (*str++)
			i++;
	return (i);
}
/*koli4estvo simvolov v stroke*/