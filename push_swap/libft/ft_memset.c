/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:04:31 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 22:57:12 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;
	char	*b;

	i = 0;
	b = dest;
	while (i < len)
	{
		b[i] = c;
		i++;
	}
	return (dest);
}
