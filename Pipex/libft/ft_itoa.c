/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:14:48 by snicky            #+#    #+#             */
/*   Updated: 2021/10/18 22:57:10 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int c)
{
	int	len;

	if (c == 0)
		return (1);
	else if (c == -2147483648)
		return (11);
	else if (c < 0)
	{
		len = 1;
		c *= -1;
	}
	else
		len = 0;
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}

char	*ft_res(int c, int len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (c == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		c = 147483648;
	}
	if (c == 0)
		res[0] = '0';
	if (c < 0)
	{
		res[0] = '-';
		c *= -1;
	}
	res[len--] = '\0';
	while (c > 0)
	{
		res[len--] = (c % 10 + 48);
		c /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	return (ft_res(n, ft_len(n)));
}
