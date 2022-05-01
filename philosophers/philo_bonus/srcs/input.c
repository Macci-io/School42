/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:20 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:23 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*skip_zero(char *str, int sign)
{
	char	*tmp;

	tmp = str;
	if (sign == 1)
		tmp++;
	while (*tmp == '0' && *tmp != '\0')
		tmp++;
	return (tmp);
}

static int	is_str_equal_digit_nbr(int nbr, char *str, int sign)
{
	if (n_digits(nbr) != (int)ft_strlen(str) - sign)
		if (n_digits(nbr) != (int)ft_strlen((skip_zero(str, sign))))
			return (0);
	return (1);
}

static int	is_positive_int(char *argv)
{
	int		nbr;
	int		sign;
	char	*str;

	nbr = ft_atoi(argv);
	str = ft_strtrim(argv, " ");
	sign = 0;
	if (str[0] == '+')
		sign = 1;
	if (ft_strchr(str, '-') == NULL)
	{
		if (is_str_equal_digit_nbr(nbr, str, sign))
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

/** t_die and etc 
 * 	is unsign needs negative check before assign value
**/

int	check_input(int argc, char **argv, t_args *p)
{
	int		i;

	i = 1;
	init_args(p);
	while (i < argc)
		if (!(is_positive_int(argv[i++])))
			return (0);
	p->n = ft_atoi(argv[1]);
	p->t_die = ft_atoi(argv[2]);
	p->t_eat = ft_atoi(argv[3]);
	p->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		p->n_meal = ft_atoi(argv[5]);
		if (p->n_meal < 0)
			return (0);
	}
	if (p->n < 1 || p->n > 200 || p->t_die < 60 \
	|| p->t_eat < 60 || p->t_sleep < 60)
		return (0);
	return (1);
}
