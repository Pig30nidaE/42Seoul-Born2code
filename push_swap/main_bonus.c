/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:46:57 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/23 20:24:11 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_list	**arr_a;
	t_list	**arr_b;
	int		*prp_arr;
	int		arr_size;

	if (argc > 1)
		arr_size = get_base_arr_size(argv);
	else
		return (0);
	arr_a = (t_list **)malloc(sizeof(t_list *) * arr_size);
	arr_b = (t_list **)malloc(sizeof(t_list *) * arr_size);
	arr_init(argc, argv, arr_a, arr_b);
	pre_sort(&prp_arr, arr_size, ft_lstfirst(*arr_a));
	if (redundancy_check(prp_arr, arr_size))
		error_exit();
	run_operations(arr_a, arr_b);
	check_sorted(arr_a, arr_b);
	clear_lst(arr_a, arr_b);
}

void	check_sorted(t_list **arr_a, t_list **arr_b)
{
	if (is_all_sorted(arr_a) && ft_lstsize(*arr_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	clear_lst(t_list **arr_a, t_list **arr_b)
{
	ft_lstclear(arr_a);
	ft_lstclear(arr_b);
}
