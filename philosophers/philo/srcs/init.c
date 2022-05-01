/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:12 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:14 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_data(t_philo **t, t_philos *p, t_args *a, int i)
{
		(*t)[i].args = a;
		(*t)[i].last_meal_time = get_time();
		(*t)[i].startup_time = p->start_time;
		(*t)[i].meals = 0;
		(*t)[i].n = i;
		(*t)[i].status = '0';
		(*t)[i].n_str = ft_itoa(i + 1);
		(*t)[i].watcher_ref = (struct s_philos *) p;
}

int	init_philo_struct(t_philo **t, t_philos *p, t_args *a)
{
	int		i;

	i = 0;
	while (i < a->n)
	{
		init_data(t, p, a, i);
		if (!(*t)[i].n_str)
			return (free_n_str(t, i) + destroy_mutex(t, i));
		pthread_mutex_init(&(*t)[i].m_fork, NULL);
		pthread_mutex_init(&(*t)[i].m_eat, NULL);
		(*t)[i].m_write = &p->m_write;
		ref_onforks(t, i, a);
		i++;
	}
	return (1);
}

void	init_args_struct(t_args *args)
{
	args->n = -1;
	args->t_die = -1;
	args->t_eat = -1;
	args->t_sleep = -1;
	args->n_meal = -1;
}

int	init_t_philos_struct(t_philos *p, t_args *arg)
{
	p->args = arg;
	p->all_eat = 1;
	if (p->args->n_meal > 0)
		p->all_eat = p->args->n_meal;
	p->start_time = get_time();
	pthread_mutex_init(&p->m_write, NULL);
	return (1);
}

/* if (i % 2 == 0 && i == a->n - 1)
			(*t)[i].next = (struct s_philo *) &(*t)[0];
		else if (i % 2 == 0)
			(*t)[i].next = (struct s_philo *) &(*t)[i + 1];
		if (i % 2 != 0)
			(*t)[i].next = (struct s_philo *) &(*t)[i - 1]; */
