/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:42:54 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 22:59:45 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	pp;

	i = 0;
	pp = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == pp)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
