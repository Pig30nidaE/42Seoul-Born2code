/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:08:06 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/16 15:36:32 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char str, int *i)
{
	if (str == '-' || str == '+')
	{
		(*i)++;
		if (str == '-')
			return (-1);
		return (1);
	}
	if ('0' <= str && str <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] == ' ') || (9 <= str[i] && str[i] <= 13))
		i++;
	sign = get_sign(str[i], &i);
	while ('0' <= str[i] && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	return (sign * num);
}
