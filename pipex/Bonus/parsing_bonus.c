/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:36:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 14:51:57 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path_env(char **env)
{
	while (*env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (ft_split(*env + 5, ':'));
		env++;
	}
	return (0);
}

void	get_cmd_arg(t_arg *arg, char **argv)
{
	int	argv_index;
	int	cmd_index;
	int	size;

	argv_index = 2;
	size = get_malloc_size(argv);
	if (arg->dog_flag)
	{
		argv_index = 3;
		size--;
	}
	arg->cmd.cmd = (char **)malloc(sizeof(char *) * size);
	cmd_index = -1;
	arg->cmd.c_arg = (t_cmd_arg *)malloc(sizeof(t_cmd_arg) * size);
	while ((++cmd_index) < size)
	{
		arg->cmd.c_arg[cmd_index].arg_arr = ft_split(argv[argv_index], ' ');
		arg->cmd.cmd[cmd_index] = arg->cmd.c_arg[cmd_index].arg_arr[0];
		argv_index++;
	}
	arg->m_size = size;
}

int	check_here_doc(t_arg *arg, char *argv1)
{
	arg->dog_flag = 0;
	if (!ft_strncmp(argv1, "here_doc\0", 9))
	{
		arg->dog_flag = 1;
		return (1);
	}
	return (0);
}

int	get_malloc_size(char **argv)
{
	int	size;

	size = 0;
	while (*argv)
	{
		size++;
		argv++;
	}
	return (size - 3);
}
