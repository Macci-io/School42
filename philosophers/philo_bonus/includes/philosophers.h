/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:19:00 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:19:28 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_args
{
	int			n;
	u_int64_t	t_die;
	u_int64_t	t_eat;
	u_int64_t	t_sleep;
	int			n_meal;
}				t_args;

typedef struct s_philo
{
	t_args				*args;
	int					n;
	pid_t				id;
	char				*n_str;
	int					meals;
	u_int64_t			last_meal_time;
	sem_t				*status;
	struct s_watcher	*info;
}					t_philo;

typedef struct s_watcher
{
	int				n;
	u_int64_t		t_die;
	u_int64_t		t_eat;
	u_int64_t		t_sleep;
	int				n_meal;
	t_philo			*philos;
	u_int64_t		stime;
	int				all_eat;
	sem_t			*acting;
	sem_t			*eaten_count_reached;
	sem_t			*stop;
	sem_t			*forks;
}				t_watcher;

/** string functions  **/
int			ft_atoi(const char *str);
char		*ft_itoa(u_int64_t n);
size_t		ft_strlen(const char *s);
int			n_digits(int n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);

/*** utils  **/
int			check_input(int argc, char **argv, t_args *p);
u_int64_t	get_time(void);
int			ft_malloc(void *dest, size_t size);
int			error_exit(char *msg, int exit_code);
void		philo_routine(t_philo *philo);
void		print_action(t_philo *philo, char *str);
void		*watch(void *arg);
void		*watch_meals(void *arg);
void		*watch_stop(void *arg);
char		*name(char *name, int nbr);

/**	init	**/
void		init_args(t_args *args);
int			init_info(t_watcher *info, t_args *args);

#endif
