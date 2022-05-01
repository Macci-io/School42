/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:05 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:07 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static u_int64_t	ft_nbr_size(u_int64_t n)
{
	u_int64_t	size;

	size = 1;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_convint(u_int64_t num, char *res, \
u_int64_t nbr_size)
{
	res[nbr_size--] = '\0';
	while (num > 0)
	{
		res[nbr_size--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(u_int64_t n)
{
	u_int64_t		nbr_size;
	u_int64_t		num;
	char			*res;

	nbr_size = ft_nbr_size(n);
	num = n;
	res = (char *)malloc(sizeof(char) * nbr_size + 1);
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	ft_convint(num, res, nbr_size);
	return (res);
}

int	uint64_digits(u_int64_t n)
{
	int			i;

	i = 1;
	n = n / 10;
	while (n > (u_int64_t)0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
