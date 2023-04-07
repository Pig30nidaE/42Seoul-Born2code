/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:27:20 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 22:56:29 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int *count, char specifier)
{
	if (specifier == 'x')
		return (ft_print_lowerhex(num, count));
	else
		return (ft_print_upperhex(num, count));
}

int	ft_print_lowerhex(unsigned int num, int *count)
{
	if (num >= 16)
	{
		if (ft_print_lowerhex(num / 16, count) < 0)
			return (-1);
	}
	return (ft_putchr("0123456789abcdef"[num % 16], count));
}

int	ft_print_upperhex(unsigned int num, int *count)
{
	if (num >= 16)
	{
		if (ft_print_upperhex(num / 16, count) < 0)
			return (-1);
	}
	return (ft_putchr("0123456789ABCDEF"[num % 16], count));
}
