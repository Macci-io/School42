/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:33 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 22:57:07 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*str;
	size_t	i;

	dst = (char *)dest;
	str = (char *)src;
	i = 0;
	if (dst == 0 && str == 0)
		return (dst);
	if (dst > str)
	{
		while (n--)
			dst[n] = str[n];
	}
	else if (dst < str)
	{
		while (i < n)
		{
			dst[i] = str[i];
			i++;
		}
	}
	return (dst);
}
