/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:25:57 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 22:57:48 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	res;

	a = 0;
	b = 0;
	res = 0;
	while (dst[a])
		a++;
	while (src[res])
		res++;
	if (dstsize <= a)
		res += dstsize;
	else
		res += a;
	while (src[b] && (a + 1) < dstsize)
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (res);
}
