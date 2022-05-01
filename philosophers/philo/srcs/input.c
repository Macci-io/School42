/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:17 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:20 by snicky           ###   ########.fr       */
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

static int	is_int(char *argv)
{
	int		nbr;
	int		sign;
	char	*str;

	nbr = ft_atoi(argv);
	str = ft_strtrim(argv, " ");
	sign = 0;
	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (n_digits(nbr) != (int)ft_strlen(str) - sign)
	{
		if (n_digits(nbr) != (int)ft_strlen((skip_zero(str, sign))))
		{
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

int	check_input(int argc, char **argv, t_args *p)
{
	int		i;

	i = 1;
	init_args_struct(p);
	while (i < argc)
		if (!(is_int(argv[i++])))
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

static void	make_ref(t_philo **t, int i, int inext, int iprev)
{
	(*t)[i].next = (struct s_philo *) &(*t)[inext];
	(*t)[i].prev = (struct s_philo *) &(*t)[iprev];
}

void	ref_onforks(t_philo **t, int i, t_args *a)
{
	if (a->n == 1)
		make_ref(t, i, i, i);
	else if (i == a->n - 1)
		make_ref(t, i, 0, i - 1);
	else if (i % 2 == 0 && i == 0 && a->n != 1)
		make_ref(t, i, i + 1, a->n - 1);
	else if (i % 2 == 0)
		make_ref(t, i, i + 1, i - 1);
	else if (i % 2 != 0)
		make_ref(t, i, i + 1, i - 1);
}
