/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:40 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:42 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	update_all_eat_count(t_philo **t)
{
	int	have_eat;
	int	i;

	i = (*t)[0].args->n;
	have_eat = (*t)[0].args->n_meal;
	if ((*t)[0].args->n == 1)
		return (0);
	while (--i > 0)
	{
		if ((*t)[i].meals < have_eat)
			return (0);
	}
	return (1);
}

/**	
 * all_eat = 0 if done
 * all_eat = -1 if somebody's died
 * **/
static void	count_meals(t_philo **t, int i, int *n)
{
	if ((*t)[i].args->n_meal > 0 && update_all_eat_count(t) == 1)
	{
		(*t)[i].watcher_ref->all_eat = 0;
		*n = 0;
	}
}

static int	set_death(t_philo **t, int i, int *n)
{
	t_philos	*w;
	int			k;

	k = 0;
	w = (*t)[i].watcher_ref;
	pthread_mutex_lock(&w->m_write);
	(*t)[i].status = DIED;
	slyly_print_mls(get_time() - (*t)[i].startup_time);
	write(1, " ", 1);
	write(1, (*t)[i].n_str, ft_strlen((*t)[i].n_str));
	write(1, " died\n", 7);
	while (k < w->args->n)
		(*t)[k++].status = DIED;
	(*t)[i].watcher_ref->all_eat = -1;
	*n = -1;
	pthread_mutex_unlock(&w->m_write);
	return (-1);
}

int	is_alive(t_philo **t, int i, int *n)
{
	if ((*t)[i].watcher_ref->args->n_meal > 0)
		count_meals(t, i, n);
	if ((*t)[i].status == DIED)
		return (-1);
	if ((*t)[i].status != DIED && (*t)[i].watcher_ref->all_eat > 0)
	{
		if ((*t)[i].status != EAT && \
		(get_time() - (*t)[i].last_meal_time) > (*t)[i].args->t_die)
			return (-1);
	}
	else if ((*t)[i].watcher_ref->all_eat == 0)
		return (0);
	return (1);
}

void	*watcher_routine(void *arg)
{
	t_philo		**t;
	int			i;
	int			n;
	int			result;

	t = (t_philo **) arg;
	n = (*t)[0].args->n;
	while (n > 0)
	{
		i = 0;
		n = (*t)[0].args->n;
		while (i < n)
		{
			result = is_alive(t, i, &n);
			if (result == -1)
				return ((void *)(size_t) set_death(t, i, &n));
			else if (result == 0)
				return ((void *)(size_t) output(t, i));
			i++;
		}
		usleep(100);
	}
	return ((void *) 1);
}
