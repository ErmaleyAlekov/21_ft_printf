/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/04/18 15:33:42 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			srcrazm;
	size_t			zna4raz;
	unsigned int	i;

	i = 0;
	srcrazm = ft_strlen(dst);
	zna4raz = ft_strlen(src);
	if (dstsize == 0)
		return (zna4raz);
	if (srcrazm > dstsize)
		return (dstsize + zna4raz);
	i = 0;
	while (dstsize > i + srcrazm + 1 && src[i])
	{
		dst[srcrazm + i] = src[i];
		i++;
	}
	dst[srcrazm + i] = '\0';
	return (srcrazm + zna4raz);
}
/*strlcat dobavlyayet stroku src v konets dst.
On budet dobavlyat ne boleye dstsize - strlen (dst) - 1 simvolov.*/