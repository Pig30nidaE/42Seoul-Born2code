/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:23:55 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 20:34:00 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->util));
	if (philo->args->philo_must_eat_time == philo->eating_count
		&& philo->args->philo_must_eat_time != -1)
	{
		pthread_mutex_unlock(&(philo->args->util));
		return (1);
	}
	pthread_mutex_unlock(&(philo->args->util));
	return (0);
}

void	*philo_start(void *parm)
{
	t_philo	*philo;

	philo = parm;
	if (!(philo->name % 2))
		usleep(1000);
	while (TRUE)
	{
		if (check_philo_finish_eating(philo))
			return (0);
		if (philo->args->philo_num == 1)
		{
			philo_behvr_print(philo, "has taken a left fork");
			return (0);
		}
		philo_pick_forks(philo);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
		pthread_mutex_lock(&(philo->args->util));
		if (philo->args->finish_flag)
			break ;
		pthread_mutex_unlock(&(philo->args->util));
	}
	pthread_mutex_unlock(&(philo->args->util));
	return (0);
}

void	birth_philosophers(t_philo *philo)
{
	int	i;

	i = -1;
	philo->args->start_time = get_time();
	while ((++i) < philo->args->philo_num)
		pthread_mutex_init(&philo->args->fork[i], 0);
	pthread_mutex_init(&philo->args->util, 0);
	pthread_mutex_init(&philo->args->print, 0);
	i = -1;
	while ((++i) < philo->args->philo_num)
	{
		pthread_create(&philo[i].thread, NULL,
			(void *)philo_start, (void *)&philo[i]);
	}
	monitoring(philo);
	i = -1;
	while ((++i) < philo->args->philo_num)
		pthread_join(philo[i].thread, 0);
}
