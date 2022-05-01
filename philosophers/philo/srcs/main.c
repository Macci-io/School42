/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:17:24 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:17:26 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * 		1	:	thread finished own routine
 * 		0	:	number_of_times_each_philosopher_must_eat have reached
 * 		-1	:	somebody's died
 * **/

static void	free_data(t_philos *info)
{
	usleep(100);
	detach_n_threads(&info->philos, info->args->n);
	free_n_str(&info->philos, info->args->n);
	destroy_mutex(&info->philos, info->args->n);
	free(info->philos);
	pthread_mutex_destroy(&info->m_write);
}

void	clear_all(t_philos *info, int thread_event)
{
	if (thread_event == 1)
		free_data(info);
	else if (thread_event == 0)
		free_data(info);
	else if (thread_event == -1)
		free_data(info);
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_philos	info;
	int			*result;

	init_args_struct(&args);
	if (!(argc == 6 || argc == 5))
		return (1 + 0 * write(1, "Error: Wrong arguments\n", 24));
	if (check_input(argc, argv, &args))
	{
		if (!setup_threads(&info, &args))
			return (1 + 0 * write(1, "Error: Threads are not created\n", 32));
		if (pthread_join(info.watcher, (void **) &result) != 0)
			clear_all(&info, *result);
	}
	else
		return (1 + 0 * write(1, "Error: Wrong arguments\n", 24));
	return (0);
}
