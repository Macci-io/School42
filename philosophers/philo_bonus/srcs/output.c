/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:20:30 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:20:32 by snicky           ###   ########.fr       */
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

int	error_exit(char *msg, int exit_code)
{
	write(1, msg, ft_strlen(msg));
	return (exit_code);
}

void	print_action(t_philo *philo, char *str)
{
	sem_wait(philo->info->acting);
	printf("%llu %d %s\n", get_time() - philo->info->stime, philo->n + 1, str);
	sem_post(philo->info->acting);
}

int	ft_malloc(void *dest, size_t size)
{
	*(void **)dest = malloc(size);
	if (*(void **)dest == NULL)
		return (1);
	memset(*(void **)dest, 0, size);
	return (0);
}
