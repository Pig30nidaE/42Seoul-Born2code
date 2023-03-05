/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:52:31 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/24 16:53:34 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ra(int print_flag)
{
	if (print_flag)
		write(1, "ra\n", 3);
}

void	print_rb(int print_flag)
{
	if (print_flag)
		write(1, "rb\n", 3);
}

void	print_rr(int print_flag)
{
	if (print_flag)
		write(1, "rr\n", 3);
}
