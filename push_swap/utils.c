/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:24:22 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 04:10:31 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(int **return_arr, int size, t_list *input_arr)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	*return_arr = (int *)malloc(sizeof(int) * size);
	while (++i < size)
	{
		(*return_arr)[i] = input_arr->content;
		input_arr = input_arr->next;
	}
	while ((--i) > 0)
	{
		j = -1;
		while ((++j) < i)
		{
			if ((*return_arr)[j] > (*return_arr)[j + 1])
			{
				temp = (*return_arr)[j];
				(*return_arr)[j] = (*return_arr)[j + 1];
				(*return_arr)[j + 1] = temp;
			}
		}
	}
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || str[i] == '-')
		{
			if (i == 0)
			{
				if (!str[i + 1] && str[i] == '-')
					return (0);
			}
			if (i > 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	system("leaks push_swap");
	exit(1);
}

int	get_max(t_list *first)
{
	int	max;

	max = 0;
	while (first)
	{
		if (first->content > max)
			max = first->content;
		first = first->next;
	}
	return (max);
}

int	get_min(t_list *last, int max)
{
	int	min;

	min = max;
	while (last)
	{
		if (last->content < min)
			min = last->content;
		last = last->prev;
	}
	return (min);
}
