/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:33:42 by sanghyol          #+#    #+#             */
/*   Updated: 2023/06/06 12:16:14 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	return (TRUE);
}
