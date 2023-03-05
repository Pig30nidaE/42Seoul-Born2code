/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_comb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:54:13 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/19 20:17:51 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_sa(t_list **arr_a)
{
	rra(*arr_a, 1);
	sa(*arr_a, 1);
}

void	ra_sa(t_list **arr_a)
{
	ra(*arr_a, 1);
	sa(*arr_a, 1);
}

void	pa_ra(t_list **arr_a, t_list **arr_b)
{
	pa(arr_a, arr_b, 1);
	ra(*arr_a, 1);
}
