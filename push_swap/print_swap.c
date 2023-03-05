/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:50:53 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 15:42:21 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sa(int print_flag)
{
	if (print_flag)
		write(1, "sa\n", 3);
}

void	print_sb(int print_flag)
{
	if (print_flag)
		write(1, "sb\n", 3);
}

void	print_ss(int print_flag)
{
	if (print_flag)
		write(1, "ss\n", 3);
}
