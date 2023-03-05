/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:50:31 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/24 16:50:41 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pb(int print_flag)
{
	if (print_flag)
		write(1, "pb\n", 3);
}

void	print_pa(int print_flag)
{
	if (print_flag)
		write(1, "pa\n", 3);
}
