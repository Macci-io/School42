/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:15:44 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:21:46 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_n_str(t_philo **t, int end)
{
	int	i;

	i = 0;
	while (i < end)
		free((*t)[i++].n_str);
	return (0);
}

int	destroy_mutex(t_philo **t, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{	
		pthread_mutex_destroy(&(*t)[i++].m_fork);
		pthread_mutex_destroy(&(*t)[i++].m_eat);
	}
	return (0);
}

int	detach_n_threads(t_philo **t, int end)
{
	int	i;

	i = 0;
	while (i < end)
		pthread_detach((*t)[i++].philo);
	return (0);
}

int	destroy_oddeven_threads(t_philo **t, int end)
{
	int	i;

	if (end % 2 == 0)
	{
		i = 0;
		while (i < end)
		{
			pthread_detach((*t)[i].philo);
			i += 2;
		}
	}
	else
	{
		i = 1;
		while (i < end)
		{
			pthread_detach((*t)[i].philo);
			i += 2;
		}
	}
	return (0);
}
