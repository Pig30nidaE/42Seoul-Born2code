/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:59:39 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 22:51:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, int *count)
{
	int		i;

	i = -1;
	if (str == 0)
	{
		(*count) += 6;
		if (write(1, "(null)", 6) < 0)
			return (-1);
	}
	else
	{
		while (*(str + (++i)))
		{
			(*count)++;
			if (write(1, &str[i], 1) < 0)
				return (-1);
		}
	}
	return (0);
}
