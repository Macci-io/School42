/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:15:54 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:15:57 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**	full **/

int	n_digits(int n)
{
	int	i;

	i = 1;
	n = n / 10;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static const char	*ft_skip(const char *s)
{
	const char	*point;

	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\f' || \
			*s == '\r' || *s == '\v')
		s++;
	point = s;
	return (point);
}

static int	ft_limit(long long n, const char *s, int sign)
{
	long long	min;
	long long	max;

	min = ((n * 10) + (*s - '0')) * sign;
	if (min < -2147483648)
		return (0);
	max = ((n * 10) + (*s - '0')) * sign;
	if (max > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			nbr;
	int			sign;
	const char	*t;
	int			check_limit;

	nbr = 0;
	sign = 1;
	t = ft_skip(str);
	if (*t == '-')
		sign = -1;
	if (*t == '-' || *t == '+')
		t++;
	while (*t >= '0' && *t <= '9')
	{
		check_limit = ft_limit(nbr, t, sign);
		if (check_limit == 0 || check_limit == -1)
			return (check_limit);
		nbr = nbr * 10 + *t++ - '0';
	}
	return (nbr * sign);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*pstr;
	unsigned int	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	pstr = str;
	while (*s1)
		*pstr++ = *s1++;
	while (*s2)
		*pstr++ = *s2++;
	*pstr = '\0';
	return (str);
}
