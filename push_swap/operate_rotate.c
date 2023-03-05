/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:13:01 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 18:14:04 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *arr_a, int print_flag)
{
	t_list	*first;
	t_list	*last;

	first = ft_lstfirst(arr_a);
	last = ft_lstlast(arr_a);
	if (ft_lstsize(arr_a) <= 1)
		return ;
	last->next = first;
	last->prev->next = 0;
	last->prev = 0;
	first->prev = last;
	print_ra(print_flag);
}

void	rb(t_list *arr_b, int print_flag)
{
	t_list	*first;
	t_list	*last;

	first = ft_lstfirst(arr_b);
	last = ft_lstlast(arr_b);
	if (ft_lstsize(arr_b) <= 1)
		return ;
	last->next = first;
	last->prev->next = 0;
	last->prev = 0;
	first->prev = last;
	print_rb(print_flag);
}

void	rr(t_list *arr_a, t_list *arr_b)
{
	ra(arr_a, 0);
	rb(arr_b, 0);
	print_rr(1);
}

void	rr_with_no_print(t_list *arr_a, t_list *arr_b)
{
	ra(arr_a, 0);
	rb(arr_b, 0);
}
