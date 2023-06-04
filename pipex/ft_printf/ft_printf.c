/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:23:12 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 22:51:10 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		bytes;
	va_list	ap;

	va_start(ap, format);
	bytes = format_replace(ap, format);
	if (bytes < 0)
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	return (bytes);
}

int	format_replace(va_list ap, const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;
			if (type_check(ap, *(format + i), &count) < 0)
				return (-1);
		}
		else
		{
			count++;
			if (write(1, format + i, 1) < 0)
				return (-1);
		}
		i++;
	}
	return (count);
}

int	type_check(va_list ap, char specifier, int *count)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int), count));
	else if (specifier == 'u')
		return (ft_unputnbr(va_arg(ap, unsigned int), count));
	else if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *), count));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), count, specifier));
	else if (specifier == 'p')
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
		(*count) += 2;
		return (ft_print_memory(va_arg(ap, unsigned long long), count));
	}
	else if (specifier == '%')
		return (ft_putchr('%', count));
	else if (specifier == 'c')
		return (ft_putchr(va_arg(ap, int), count));
	return (0);
}
