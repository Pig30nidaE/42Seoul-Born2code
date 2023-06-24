/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:27:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 18:37:17 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo)
{
	while (TRUE)
	{
		if (is_philo_died(philo))
		{
			pthread_mutex_lock(&(philo->args->util));
			philo->args->finish_flag = TRUE;
			pthread_mutex_unlock(&(philo->args->util));
			return ;
		}
		if (is_all_philos_finished_eating(philo))
		{
			pthread_mutex_lock(&(philo->args->util));
			philo->args->finish_flag = TRUE;
			pthread_mutex_unlock(&(philo->args->util));
			return ;
		}
	}
	return ;
}
