/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:15 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:17 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_args(t_args *args)
{
	args->n = -1;
	args->t_die = -1;
	args->t_eat = -1;
	args->t_sleep = -1;
	args->n_meal = -1;
}

static sem_t	*semaphore_open(const char *key, unsigned int value)
{
	sem_t	*sem_name;

	sem_name = sem_open(key, O_CREAT | O_EXCL, 0644, value);
	if (sem_name != SEM_FAILED)
		return (sem_name);
	sem_unlink(key);
	return (sem_open(key, O_CREAT | O_EXCL, 0644, value));
}

static void	save_args(t_watcher **info, t_args **args)
{
	(*info)->n = (*args)->n;
	(*info)->t_die = (*args)->t_die;
	(*info)->t_eat = (*args)->t_eat;
	(*info)->t_sleep = (*args)->t_sleep;
	(*info)->n_meal = (*args)->n_meal;
}

int	init_info(t_watcher *info, t_args *args)
{
	int	i;

	save_args(&info, &args);
	info->stop = semaphore_open("stop", 0);
	info->acting = semaphore_open("acting", 1);
	info->forks = semaphore_open("forks", info->n);
	info->eaten_count_reached = semaphore_open("eaten_count_reached", 0);
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->n))
		return (error_exit("Error: Can't allocate memory\n", 1));
	i = 0;
	while (i < info->n)
	{
		info->philos[i].n_str = name("philo", i);
		info->philos[i].status = semaphore_open(info->philos[i].n_str, 1);
		info->philos[i].n = i;
		info->philos[i].info = info;
		i++;
	}
	return (0);
}

char	*name(char *name, int nbr)
{
	char	*result;
	int		num;
	int		i;

	i = 0;
	num = nbr;
	while (num)
	{
		num /= 10;
		++i;
	}
	result = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
	if (result == NULL)
		return (NULL);
	num = -1;
	while (++num < i)
		result[num] = name[num];
	while (nbr)
	{
		result[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	result[i] = 0;
	return (result);
}
