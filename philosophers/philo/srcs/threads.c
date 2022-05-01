/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:49 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:52 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*create_treads(t_philos *p)
{
	t_philo	*t;

	t = (t_philo *) malloc(sizeof(t_philo) * p->args->n);
	if (!t)
		return (NULL);
	if (!init_philo_struct(&t, p, p->args))
	{
		free(t);
		return (NULL);
	}
	return (t);
}

int	start_threads(t_philo **t)
{
	int		i;

	i = 0;
	while (i < (*t)->args->n)
	{
		if (pthread_create(&(*t)[i].philo, NULL, &philo_routine, &(*t)[i]))
			return (destroy_oddeven_threads(t, i) + destroy_mutex(t, i) \
			+ free_n_str(t, i));
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < (*t)->args->n)
	{
		if (pthread_create(&(*t)[i].philo, NULL, &philo_routine, &(*t)[i]))
			return (destroy_oddeven_threads(t, i) + destroy_mutex(t, i) \
			+ free_n_str(t, i));
		i += 2;
	}
	return (1);
}

static int	error_clear_mutexes(t_philos *info)
{
	detach_n_threads(&info->philos, info->args->n);
	free_n_str(&info->philos, info->args->n);
	destroy_mutex(&info->philos, info->args->n);
	free(info->philos);
	pthread_mutex_destroy(&info->m_write);
	return (0);
}

/** already clear mutexes and detached philo threads if failed**/

int	setup_threads(t_philos *p, t_args *args)
{
	if (!init_t_philos_struct(p, args))
		return (0);
	p->philos = create_treads(p);
	if (!p->philos)
		return (0 * pthread_mutex_destroy(&p->m_write));
	if (!start_threads(&(p->philos)))
	{
		free(p->philos);
		return (0 * pthread_mutex_destroy(&p->m_write));
	}
	if (pthread_create(&p->watcher, NULL, &watcher_routine, &(p->philos)))
		return (error_clear_mutexes(p));
	return (1);
}
