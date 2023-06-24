/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:48:15 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/06 12:29:21 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_under_zero(t_args *args)
{
	if (args->philo_num <= 0 || args->dead_time <= 0 || args->eating_time <= 0
		|| args->sleep_time <= 0)
	{
		args->finish_flag = TRUE;
		return (1);
	}
	return (0);
}

void	args_init(int argc, char **argv, t_args *args)
{
	args->finish_flag = FALSE;
	args->philo_num = ft_atoi(argv[PHILO_NUM]);
	args->dead_time = ft_atoi(argv[DEAT_T]);
	args->eating_time = ft_atoi(argv[EATING_T]);
	args->sleep_time = ft_atoi(argv[SLEEP_T]);
	if (check_args_under_zero(args))
		return ;
	if (argc == 5)
		args->philo_must_eat_time = -1;
	else
	{
		args->philo_must_eat_time = ft_atoi(argv[PHILO_MUST_EAT_T]);
		if (args->philo_must_eat_time <= 0)
		{
			args->finish_flag = TRUE;
			return ;
		}
	}
	if (args->philo_num > 1)
		args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* args->philo_num);
	else
		args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* 1);
}

void	philo_init(t_args *args, t_philo **philo)
{
	int	i;

	i = -1;
	while ((++i) < args->philo_num)
	{
		(*philo)[i].eating_count = 0;
		(*philo)[i].last_eat_time = 0;
		(*philo)[i].name = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].args = args;
		if (i + 1 >= args->philo_num)
			(*philo)[i].right_fork = 0;
		else
			(*philo)[i].right_fork = i + 1;
	}
}
