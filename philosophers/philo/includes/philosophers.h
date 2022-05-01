/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:14:26 by snicky            #+#    #+#             */
/*   Updated: 2022/04/26 01:14:30 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define EAT	'e'
# define SLEEP	's'
# define THINK	't'
# define DIED	'd'
# define FORK	'f'
# define CLOSE	'c'

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
	t_args			*args;

	int				n;
	char			*n_str;
	int				meals;
	char			status;
	pthread_t		philo;
	pthread_mutex_t	m_fork;
	u_int64_t		last_meal_time;
	u_int64_t		startup_time;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_philos	*watcher_ref;
	pthread_mutex_t	*m_write;
	pthread_mutex_t	m_eat;
}					t_philo;

typedef struct s_philos
{
	t_args			*args;
	t_philo			*philos;
	u_int64_t		start_time;
	int				all_eat;
	pthread_t		watcher;
	pthread_mutex_t	m_write;
}				t_philos;

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
int			uint64_digits(u_int64_t n);
void		slyly_print_mls(u_int64_t micro_s);
char		*put_msg(char act);
void		print_action(t_philo *p, char act);
int			take_fork(t_philo *t);
void		is_eating(t_philo *p);
void		is_sleeping(t_philo *p);
void		is_thinking(t_philo *p);
int			output(t_philo **t, int i);
void		ft_usleep(u_int64_t mls, t_philo *t);
void		ref_onforks(t_philo **t, int i, t_args *a);

/** init & free  **/
int			init_philo_struct(t_philo **t, t_philos *p, t_args *a);
void		init_args_struct(t_args *args);
int			init_t_philos_struct(t_philos *p, t_args *arg);
int			init_watcher_thread(t_philos *p);
int			free_n_str(t_philo **t, int end);
int			destroy_mutex(t_philo **t, int end);
int			detach_n_threads(t_philo **t, int end);
int			destroy_oddeven_threads(t_philo **t, int end);
void		clear_all(t_philos *info, int thread_event);

/*** threads **/
t_philo		*create_treads(t_philos *p);
int			start_threads(t_philo **t);
int			setup_threads(t_philos *p, t_args *args);

/*** threads routines **/
void		*philo_routine(void *arg);
void		*watcher_routine(void *arg);

#endif
