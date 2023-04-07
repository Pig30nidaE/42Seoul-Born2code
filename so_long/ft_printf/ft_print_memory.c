/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:03:23 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 21:24:29 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(unsigned long long addr, int *count)
{
	if (addr >= 16)
		ft_print_memory(addr / 16, count);
	return (ft_putchr("0123456789abcdef"[addr % 16], count));
}
