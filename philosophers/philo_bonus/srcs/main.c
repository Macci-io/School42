/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:25 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:27 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	close_all(t_watcher *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->n)
	{
		waitpid(info->philos[i].id, &status, 0);
		sem_close(info->philos[i].status);
		free(info->philos[i].n_str);
		i++;
	}
	free(info->philos);
	sem_close(info->stop);
	sem_close(info->acting);
	sem_close(info->forks);
	sem_close(info->eaten_count_reached);
}

static void	fork_philosophers(t_watcher *info)
{
	int		i;

	i = 0;
	info->stime = get_time();
	while (i < info->n)
	{
		info->philos[i].last_meal_time = info->stime;
		info->philos[i].id = fork();
		if (info->philos[i].id == 0)
			return (philo_routine(&info->philos[i]));
		else if (info->philos[i].id < 0)
		{
			printf("Error: fail at fork creation\n");
			exit(1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_watcher	info;
	pthread_t	thread;

	if (!(argc == 6 || argc == 5))
		return (1 + 0 * write(1, "Error: Wrong arguments\n", 24));
	if (check_input(argc, argv, &args))
	{
		if (init_info(&info, &args))
			exit(1);
		fork_philosophers(&info);
		if (info.n_meal != -1 && info.n != 1)
			pthread_create(&thread, NULL, watch_meals, &info);
		pthread_create(&thread, NULL, watch_stop, &info);
		pthread_join(thread, NULL);
		pthread_detach(thread);
		close_all(&info);
	}
	else
		return (1 + 0 * write(1, "Error: Wrong arguments\n", 24));
	return (0);
}
