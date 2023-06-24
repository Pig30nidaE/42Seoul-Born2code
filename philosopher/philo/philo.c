/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:12:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/13 18:36:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_allocated(t_philo *philo)
{
	free(philo->args->fork);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (!check_argc(argc))
		return (0);
	args_init(argc, argv, &args);
	if (args.finish_flag)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo) * args.philo_num);
	philo_init(&args, &philo);
	birth_philosophers(philo);
	free_allocated(philo);
}
