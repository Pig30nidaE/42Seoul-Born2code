/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:47:56 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 22:55:36 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *count)
{
	if (n >= 0)
	{
		if (n >= 10)
		{
			if (ft_putnbr(n / 10, count) < 0)
				return (-1);
			if (ft_putnbr(n % 10, count) < 0)
				return (-1);
		}
		else
			return (ft_putchr(n + '0', count));
	}
	else
	{
		if (n == -2147483648)
			return (ft_print_str("-2147483648", count));
		else
		{
			(*count)++;
			if (write(1, "-", 1) < 0)
				return (-1);
			ft_putnbr(-1 * n, count);
		}
	}
	return (0);
}

int	ft_unputnbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		if (ft_unputnbr(n / 10, count) < 0)
			return (-1);
		if (ft_unputnbr(n % 10, count) < 0)
			return (-1);
	}
	else
		return (ft_putchr(n + '0', count));
	return (0);
}
