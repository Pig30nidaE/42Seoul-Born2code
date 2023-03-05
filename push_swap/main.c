/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:18:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/02/28 04:11:35 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**arr_a;
	t_list	**arr_b;
	int		*prp_arr;
	int		arr_size;

	if (argc <= 1)
		return (0);
	arr_size = get_base_arr_size(argv);
	if (arr_size <= 0)
		error_exit();
	arr_a = (t_list **)malloc(sizeof(t_list *) * arr_size);
	arr_b = (t_list **)malloc(sizeof(t_list *) * arr_size);
	arr_init(argc, argv, arr_a, arr_b);
	pre_sort(&prp_arr, arr_size, ft_lstfirst(*arr_a));
	if (redundancy_check(prp_arr, arr_size))
		error_exit();
	if (!exception_handling(arr_size, arr_a, arr_b))
		return (0);
	a_to_b(arr_a, arr_b, prp_arr[arr_size / 3], prp_arr[arr_size * 2 / 3]);
	free(prp_arr);
	b_to_a(arr_a, arr_b);
	surplus_sorting(arr_a);
	ft_lstclear(arr_a);
	ft_lstclear(arr_b);
	system("leaks push_swap");
}
