/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:07:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 20:44:29 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_passing_time(t_philo *philo, long long time)
{
	long long	target_time;

	pthread_mutex_lock(&philo->args->util);
	target_time = get_time();
	pthread_mutex_unlock(&philo->args->util);
	while (get_time() < target_time + time)
		usleep(100);
}

void	philo_behvr_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->args->print));
	pthread_mutex_lock(&(philo->args->util));
	if (!(philo->args->finish_flag))
	{
		printf("%lldms %d %s\n", get_time() - philo->args->start_time,
			philo->name, msg);
		pthread_mutex_unlock(&(philo->args->util));
		pthread_mutex_unlock(&(philo->args->print));
		return ;
	}
	pthread_mutex_unlock(&(philo->args->util));
	pthread_mutex_unlock(&(philo->args->print));
}

t_bool	is_philo_died(t_philo *philo)
{
	int			i;
	long long	target_time;

	i = -1;
	while ((++i) < philo->args->philo_num)
	{
		pthread_mutex_lock(&philo->args->util);
		if (philo[i].last_eat_time)
			target_time = philo[i].last_eat_time;
		else
			target_time = philo->args->start_time;
		if (get_time() - target_time >= philo->args->dead_time)
		{
			pthread_mutex_unlock(&philo->args->util);
			philo_dead(&philo[i]);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->args->util);
	}
	return (FALSE);
}

t_bool	is_all_philos_finished_eating(t_philo *philo)
{
	int	i;

	i = -1;
	while ((++i) < philo->args->philo_num)
	{
		pthread_mutex_lock(&philo->args->util);
		if (philo->args->philo_must_eat_time == -1
			|| philo[i].eating_count < philo->args->philo_must_eat_time)
		{
			pthread_mutex_unlock(&philo->args->util);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo->args->util);
	}
	return (TRUE);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
