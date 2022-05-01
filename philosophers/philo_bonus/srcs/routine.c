/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:34 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:38 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_fork(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_action(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_action(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	sem_wait(philo->status);
	philo->last_meal_time = get_time();
	print_action(philo, "is eating");
	philo->meals += 1;
	if (philo->meals == philo->info->n_meal)
		sem_post(philo->info->eaten_count_reached);
	usleep(philo->info->t_eat * 1000);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	sem_post(philo->status);
}

static void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->info->t_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	philo_routine(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, watch, philo);
	if (philo->n % 2 == 0)
		usleep(philo->info->t_eat * 1000);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		usleep(100);
	}
}
