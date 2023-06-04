/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:28:15 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:44:18 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_fd(int fd)
{
	if (fd < 0)
		print_fd_error();
}

void	check_argc(int argc)
{
	if (argc != 5)
		print_argc_error();
}

void	check_cmd(t_arg arg)
{
	while (*(arg.cmd.cmd))
	{
		if (!(*(arg.cmd.cmd)))
			print_cmd_error(0);
		(arg.cmd.cmd)++;
	}
	while (*(arg.cmd.c_arg->arg_arr))
	{
		if (!(*(arg.cmd.c_arg->arg_arr)))
			print_cmd_error(0);
		(arg.cmd.c_arg->arg_arr)++;
	}
}

void	check_env(char **env)
{
	if (!env)
		print_env_error();
	if (!(*env))
		print_env_error();
}

char	*check_cmd_path_exist(char *str)
{
	if (!access(str, F_OK))
	{
		if (access(str, X_OK))
			print_cmd_error(NO_PERMIT);
		return (str);
	}
	else
		print_fd_error();
	return (0);
}
