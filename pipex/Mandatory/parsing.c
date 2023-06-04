/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:36:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/07 18:15:17 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	arg->cmd.cmd = (char **)malloc(sizeof(char *) * 2);
	arg->cmd.c_arg = (t_cmd_arg *)malloc(sizeof(t_cmd_arg) * 2);
	arg->cmd.c_arg[0].arg_arr = ft_split(argv[2], ' ');
	arg->cmd.cmd[0] = arg->cmd.c_arg[0].arg_arr[0];
	arg->cmd.c_arg[1].arg_arr = ft_split(argv[3], ' ');
	arg->cmd.cmd[1] = arg->cmd.c_arg[1].arg_arr[0];
}
