/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:03:33 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 20:44:46 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->util));
	if (philo->args->finish_flag)
	{
		pthread_mutex_unlock(&(philo->args->util));
		return ;
	}
	pthread_mutex_unlock(&(philo->args->util));
	if (philo->args->philo_num > 1)
	{
		pthread_mutex_lock(&(philo->args->fork[philo->left_fork]));
		philo_behvr_print(philo, "has taken a left fork");
		pthread_mutex_lock(&(philo->args->fork[philo->right_fork]));
		philo_behvr_print(philo, "has taken a right fork");
	}
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->util));
	if (philo->args->finish_flag)
	{
		pthread_mutex_unlock(&(philo->args->util));
		pthread_mutex_unlock(&(philo->args->fork[philo->left_fork]));
		pthread_mutex_unlock(&(philo->args->fork[philo->right_fork]));
		return ;
	}
	pthread_mutex_unlock(&(philo->args->util));
	if (philo->args->philo_num <= 1)
		return ;
	philo_behvr_print(philo, "is eating");
	philo_passing_time(philo, philo->args->eating_time);
	pthread_mutex_lock(&(philo->args->util));
	philo->last_eat_time = get_time();
	philo->eating_count += 1;
	pthread_mutex_unlock(&(philo->args->util));
	pthread_mutex_unlock(&(philo->args->fork[philo->left_fork]));
	pthread_mutex_unlock(&(philo->args->fork[philo->right_fork]));
}

void	philo_dead(t_philo *philo)
{
	philo_behvr_print(philo, "is died");
}

void	philo_thinking(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->util));
	if (philo->args->finish_flag || philo->args->philo_num <= 1)
	{
		pthread_mutex_unlock(&(philo->args->util));
		return ;
	}
	pthread_mutex_unlock(&(philo->args->util));
	philo_behvr_print(philo, "is thinking");
}

void	philo_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->util));
	if (philo->args->finish_flag || philo->args->philo_num <= 1)
	{
		pthread_mutex_unlock(&(philo->args->util));
		return ;
	}
	pthread_mutex_unlock(&(philo->args->util));
	philo_behvr_print(philo, "is sleeping");
	philo_passing_time(philo, philo->args->sleep_time);
}
