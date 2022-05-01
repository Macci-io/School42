/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:35 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:37 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	if_one_philo(t_philo *t)
{
	if (t->next->n == t->n)
	{
		pthread_mutex_unlock(&t->m_fork);
		usleep(t->args->t_die * 1000);
		t->status = DIED;
		return (1);
	}
	return (0);
}

/**
 * backup
 *
 *  int	take_fork(t_philo *t)
	{
		pthread_mutex_lock(&t->m_fork);
		t->status = FORK;
		if (t->status != DIED && t->watcher_ref->all_eat > 0)
			print_action(t, t->status);
		if (if_one_philo(t))
			return (0);
		pthread_mutex_lock(&t->next->m_fork);
		print_action(t, t->status);
		if (t->status != DIED && t->watcher_ref->all_eat > 0)
			is_eating(t);
		pthread_mutex_unlock(&t->m_fork);
		pthread_mutex_unlock(&t->next->m_fork);
		return (1);
	}
 * **/

/**
 * about another fork?
 * **/

int	take_fork(t_philo *t)
{
	pthread_mutex_lock(&t->m_fork);
	t->status = FORK;
	if (t->status != DIED && t->watcher_ref->all_eat > 0)
		print_action(t, t->status);
	if (if_one_philo(t))
		return (0);
	pthread_mutex_lock(&t->next->m_fork);
	print_action(t, t->status);
	if (t->status != DIED && t->watcher_ref->all_eat > 0)
		is_eating(t);
	pthread_mutex_unlock(&t->m_fork);
	pthread_mutex_unlock(&t->next->m_fork);
	return (1);
}

void	*philo_routine(void *arg)
{
	t_philo	*t;

	t = (t_philo *) arg;
	while (t->status != DIED && t->watcher_ref->all_eat > 0)
	{
		if (t->n % 2 == 0)
			usleep(1000);
		if (take_fork(t))
		{
			is_sleeping(t);
			is_thinking(t);
		}
		usleep(100);
	}
	return (NULL);
}
