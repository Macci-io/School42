/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:15:34 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:15:37 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/** meals before or after ? **/
void	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->m_eat);
	p->status = EAT;
	print_action(p, p->status);
	p->last_meal_time = get_time();
	usleep(p->args->t_eat * 1000);
	p->meals++;
	pthread_mutex_unlock(&p->m_eat);
}

void	is_sleeping(t_philo *p)
{
	if (p->status != DIED && p->watcher_ref->all_eat > 0)
	{
		p->status = SLEEP;
		print_action(p, p->status);
		usleep(p->args->t_sleep * 1000);
	}
}

void	is_thinking(t_philo *p)
{
	if (p->status != DIED && p->watcher_ref->all_eat > 0)
	{
		p->status = THINK;
		print_action(p, p->status);
	}
}

/** write own usleep for more accuracy **/
void	ft_usleep(u_int64_t mls, t_philo *t)
{
	u_int64_t	wake_up;

	if (t->status == 'd' && t->watcher_ref->all_eat == 0)
		return ;
	wake_up = get_time() + mls;
	while (get_time() < wake_up)
		usleep(100);
}

/**
 * 4 310 200 100
 * 
 * 200 1 eat ->  400 - закончит есть ляжет спать
 * 	2 wait
 * 400 sleep
 * 500 start eat но не может 600 - 400 = 200
 * 500 1 is think
 * 600 is eating
 * 
 * 
 * 
 * */
