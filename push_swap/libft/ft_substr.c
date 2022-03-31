/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:28 by snicky            #+#    #+#             */
/*   Updated: 2021/10/19 22:58:16 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if ((ft_strlen (s)) < start)
		len = 0;
	if (ft_strlen(s) + start < len)
		len = ft_strlen(s + start);
	res = malloc (len + 1);
	if (!res)
		return (0);
	ft_strlcpy (res, s + start, len + 1);
	return (res);
}
