/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:30 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:32 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/** in mls**/
u_int64_t	get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (u_int64_t) 1000 + time.tv_usec / 1000);
}

void	slyly_print_mls(u_int64_t micro_s)
{
	char		*tmp;
	u_int64_t	n;

	n = uint64_digits(micro_s);
	tmp = ft_itoa(micro_s);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}

char	*put_msg(char act)
{
	if (act == EAT)
		return (" is eating\n");
	else if (act == SLEEP)
		return (" is sleeping\n");
	else if (act == FORK)
		return (" has taken a fork\n");
	else if (act == THINK)
		return (" is thinking\n");
	else if (act == DIED)
		return (" died\n");
	else
		return (" died\n");
}

/** locks output (not realy needed)**/
void	print_action(t_philo *p, char act)
{
	static char	s;

	pthread_mutex_lock(p->m_write);
	if (!s)
	{
		if (p->status != DIED && act != CLOSE)
			slyly_print_mls(get_time() - p->startup_time);
		if (p->status != DIED && act != CLOSE)
			write(1, " ", 1);
		if (p->status != DIED && act != CLOSE)
			write(1, p->n_str, ft_strlen(p->n_str));
		if (act == DIED && act == CLOSE)
			s = 'd';
		if (p->status != DIED && act != CLOSE)
			write(1, put_msg(act), ft_strlen(put_msg(act)));
	}
	pthread_mutex_unlock(p->m_write);
}

int	output(t_philo **t, int i)
{
	t_philos	*w;
	int			k;

	k = 0;
	w = (*t)[i].watcher_ref;
	pthread_mutex_lock(&w->m_write);
	slyly_print_mls(get_time() - (*t)[i].startup_time);
	write(1, " each philosopher have reached ", 32);
	write(1, "must eat count.\n", 17);
	while (k < w->args->n)
	{
		(*t)[k++].status = DIED;
	}
	pthread_mutex_unlock(&w->m_write);
	return (0);
}
