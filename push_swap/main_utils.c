/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:03:54 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/26 15:27:22 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_base_arr_size(char **argv)
{
	int		i;
	int		return_num;
	char	**temp;
	int		temp_size;

	return_num = 0;
	i = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		temp_size = arr_size(temp);
		return_num += temp_size;
		free_all(temp, temp_size + 1);
	}
	return (return_num);
}

void	surplus_sorting(t_list **arr_a)
{
	int		count;
	t_list	*a_last;

	count = 0;
	a_last = ft_lstlast(*arr_a);
	while (a_last->prev->content > a_last->content)
	{
		count++;
		a_last = a_last->prev;
		if (!(a_last->prev))
			break ;
	}
	if (!is_all_sorted(arr_a))
		surplus_rot(count, arr_a);
}

void	surplus_rot(int count, t_list **arr_a)
{
	if (count > (ft_lstsize(*arr_a) / 2))
	{
		while (ft_lstfirst(*arr_a)->content
			> ft_lstfirst(*arr_a)->next->content)
			rra(*arr_a, 1);
		rra(*arr_a, 1);
	}
	else
	{
		while (ft_lstlast(*arr_a)->content < ft_lstlast(*arr_a)->prev->content)
			ra(*arr_a, 1);
		ra(*arr_a, 1);
	}
}

void	arr_init(int argc, char **argv, t_list **arr_a, t_list **arr_b)
{
	int		i;
	int		j;
	int		index;
	char	**temp;

	i = -1;
	index = -1;
	while ((++i) + 1 < argc)
	{
		temp = ft_split(argv[i + 1], ' ');
		j = -1;
		split_check(temp);
		while ((++j) < arr_size(temp))
		{
			num_check(temp[j], temp);
			arr_a[++index] = ft_lstnew(ft_atoi(temp[j]));
			arr_b[index] = 0;
			arr_linking(arr_a, index);
			free(temp[j]);
		}
		free(temp);
	}
}
