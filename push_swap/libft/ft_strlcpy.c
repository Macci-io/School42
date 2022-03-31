/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:41:33 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 23:00:27 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (dstsize > 0)
	{
		while (src[j] && j < dstsize - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = 0;
	}
	return (ft_strlen(src));
}
