/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:26:28 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 19:42:28 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *arr_a, int print_flag)
{
	t_list	*first;
	t_list	*last;

	first = ft_lstfirst(arr_a);
	last = ft_lstlast(arr_a);
	if (ft_lstsize(arr_a) <= 1)
		return ;
	last->next = first;
	first->next->prev = 0;
	first->next = 0;
	first->prev = last;
	print_rra(print_flag);
}

void	rrb(t_list *arr_b, int print_flag)
{
	t_list	*first;
	t_list	*last;

	first = ft_lstfirst(arr_b);
	last = ft_lstlast(arr_b);
	if (ft_lstsize(arr_b) <= 1)
		return ;
	last->next = first;
	first->next->prev = 0;
	first->next = 0;
	first->prev = last;
	print_rrb(print_flag);
}

void	rrr(t_list *arr_a, t_list *arr_b)
{
	rra(arr_a, 0);
	rrb(arr_b, 0);
	print_rrr(1);
}

void	rrr_with_no_print(t_list *arr_a, t_list *arr_b)
{
	rra(arr_a, 0);
	rrb(arr_b, 0);
}
