/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:28:31 by snicky            #+#    #+#             */
/*   Updated: 2021/10/13 14:40:31 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			(ps = ((char *)s + i));
		i++;
	}
	if (ps)
		return (ps);
	if (c == s[i])
		return ((char *)s + i);
	return (NULL);
}
