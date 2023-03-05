/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:33:12 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/21 18:16:52 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *arr_a, int print_flag)
{
	t_list	*last;
	int		temp;

	if (ft_lstsize(arr_a) <= 1)
		return ;
	last = ft_lstlast(arr_a);
	temp = last->content;
	last->content = last->prev->content;
	last->prev->content = temp;
	print_sa(print_flag);
}

void	sb(t_list *arr_b, int print_flag)
{
	t_list	*last;
	int		temp;

	if (ft_lstsize(arr_b) <= 1)
		return ;
	last = ft_lstlast(arr_b);
	temp = last->content;
	last->content = last->prev->content;
	last->prev->content = temp;
	print_sb(print_flag);
}

void	ss(t_list *arr_a, t_list *arr_b)
{
	sa(arr_a, 0);
	sb(arr_b, 0);
	print_ss(1);
}

void	ss_with_no_print(t_list *arr_a, t_list *arr_b)
{
	sa(arr_a, 0);
	sb(arr_b, 0);
}
