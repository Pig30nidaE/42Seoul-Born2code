/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:53:52 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/24 16:55:11 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rra(int print_flag)
{
	if (print_flag)
		write(1, "rra\n", 4);
}

void	print_rrb(int print_flag)
{
	if (print_flag)
		write(1, "rrb\n", 4);
}

void	print_rrr(int print_flag)
{
	if (print_flag)
		write(1, "rrr\n", 4);
}
