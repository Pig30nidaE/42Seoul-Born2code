/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:22:08 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 15:13:15 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_check(char *str, char **str_start)
{
	if (!is_num(str))
	{
		free(str);
		free(str_start);
		error_exit();
	}
}

int	is_all_sorted(t_list **arr_a)
{
	t_list	*first;

	first = ft_lstfirst(*arr_a);
	while (first->next)
	{
		if (first->content < first->next->content)
			return (0);
		first = first->next;
	}
	return (1);
}

int	redundancy_check(int *prp_arr, int arr_size)
{
	int	i;

	i = -1;
	if (!prp_arr)
		return (0);
	while ((++i) + 1 < arr_size)
	{
		if (prp_arr[i] == prp_arr[i + 1])
			return (1);
	}
	return (0);
}

int	exception_handling(int arr_size, t_list **arr_a, t_list **arr_b)
{
	if (is_all_sorted(arr_a))
	{
		ft_lstclear(arr_a);
		ft_lstclear(arr_b);
		return (0);
	}
	if (argc_check(arr_size, arr_a))
		return (0);
	return (1);
}

void	split_check(char **arr)
{
	if (!arr)
		error_exit();
	if (!(arr[0]))
		error_exit();
}
