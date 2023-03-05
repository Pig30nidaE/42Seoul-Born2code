/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:37 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/24 16:56:58 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **arr_a, t_list **arr_b, int print_flag)
{
	t_list	*b_last;
	t_list	*a_last;
	t_list	*temp;

	b_last = ft_lstlast(*arr_b);
	a_last = ft_lstlast(*arr_a);
	temp = 0;
	if (!(*arr_b))
		return ;
	if (b_last->prev)
		temp = b_last->prev;
	if (!(*arr_a))
	{
		*arr_a = b_last;
		check_prev_exist(b_last);
		(*arr_a)->prev = 0;
	}
	else
	{
		check_prev_exist(b_last);
		a_last->next = b_last;
		a_last->next->prev = a_last;
	}
	*arr_b = temp;
	print_pa(print_flag);
}

void	pb(t_list **arr_a, t_list **arr_b, int print_flag)
{
	t_list	*a_last;
	t_list	*b_last;
	t_list	*temp;

	a_last = ft_lstlast(*arr_a);
	b_last = ft_lstlast(*arr_b);
	temp = 0;
	if (!(*arr_a))
		return ;
	if (a_last->prev)
		temp = a_last->prev;
	if (!(*arr_b))
	{
		*arr_b = a_last;
		check_prev_exist(a_last);
		(*arr_b)->prev = 0;
	}
	else
	{
		check_prev_exist(a_last);
		b_last->next = a_last;
		b_last->next->prev = b_last;
	}
	*arr_a = temp;
	print_pb(print_flag);
}

void	check_prev_exist(t_list	*last)
{
	if (last->prev)
		last->prev->next = 0;
}
