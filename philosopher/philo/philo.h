/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:12:13 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 20:53:06 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_NUM 1
# define DEAT_T 2
# define EATING_T 3
# define SLEEP_T 4
# define PHILO_MUST_EAT_T 5

typedef int			t_bool;

# define TRUE 1
# define FALSE 0

typedef struct s_args
{
	int				philo_num;
	int				dead_time;
	int				eating_time;
	int				sleep_time;
	int				philo_must_eat_time;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	util;
	t_bool			finish_flag;
	t_bool			eating_start_flag;
}					t_args;

typedef struct s_philo
{
	int				name;
	long long		last_eat_time;
	int				eating_count;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_args			*args;
}					t_philo;

void				args_init(int argc, char **argv, t_args *args);
void				philo_init(t_args *args, t_philo **philo);

t_bool				check_argc(int argc);
int					check_args_under_zero(t_args *args);
int					check_philo_finish_eating(t_philo *philo);

void				philo_pick_forks(t_philo *philo);
void				philo_eating(t_philo *philo);
void				philo_dead(t_philo *philo);
void				philo_thinking(t_philo *philo);
void				philo_sleeping(t_philo *philo);

void				philo_passing_time(t_philo *philo, long long time);
t_bool				is_philo_died(t_philo *philo);
t_bool				is_all_philos_finished_eating(t_philo *philo);
void				philo_behvr_print(t_philo *philo, char *msg);
long long			get_time(void);

void				monitoring(t_philo *philo);

void				birth_philosophers(t_philo *philo);
void				*philo_start(void *args);

void				free_allocated(t_philo *philo);

#endif