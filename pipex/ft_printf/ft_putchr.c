/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:48:19 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 22:50:28 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c, int *count)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (0);
}