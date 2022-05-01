/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_watch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:19:51 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:19:53 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*watch(void *arg)
{
	t_philo		*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->status);
		sem_wait(philo->info->acting);
		if ((get_time() - philo->last_meal_time) >= philo->info->t_die)
		{
			printf("%llu %d %s\n", get_time() - philo->info->stime, \
			philo->n + 1, "died");
			sem_post(philo->info->stop);
			return (NULL);
		}
		sem_post(philo->info->acting);
		sem_post(philo->status);
	}
	return (NULL);
}

void	*watch_meals(void *arg)
{
	t_watcher	*info;
	int			i;

	i = 0;
	info = arg;
	while (i++ < info->n)
		sem_wait(info->eaten_count_reached);
	sem_post(info->stop);
	return (NULL);
}

void	*watch_stop(void *arg)
{
	t_watcher	*info;
	int			i;

	info = arg;
	sem_wait(info->stop);
	i = 0;
	while (i < info->n)
		kill(info->philos[i++].id, SIGTERM);
	return (NULL);
}
