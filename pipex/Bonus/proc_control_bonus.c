/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:31 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:48:51 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	let_fork(t_arg *arg)
{
	int	count;

	count = -1;
	while ((++count) < arg->m_size)
	{
		if (pipe(arg->pipe_fd) == -1)
			print_pipe_error();
		arg->pid = fork();
		if (arg->pid == -1)
			print_fork_error();
		else if (!(arg->pid))
		{
			if (!count)
				infile_to_pipe(arg, count);
			else if (count + 1 == arg->m_size)
				pipe_to_outfile(arg);
			else
				pipe_to_pipe(arg);
			execve(find_cmd_path(arg, arg->cmd.cmd[count]),
				arg->cmd.c_arg[count].arg_arr, arg->tenv.path);
		}
		else
			parents_process(arg);
	}
	wait_process();
}

void	wait_process(void)
{
	while (wait(0) != -1)
		;
}

char	*find_cmd_path(t_arg *arg, char *cmd)
{
	char	*temp;

	if (!ft_strncmp(ft_substr(cmd, 0, 1), "/", 1) || ft_strchr(cmd, '/'))
		return (check_cmd_path_exist(cmd));
	while (*(arg->tenv.path))
	{
		temp = ft_strjoin_libft("/", cmd);
		temp = ft_strjoin_libft(*(arg->tenv.path), temp);
		if (!access(temp, F_OK))
		{
			if (access(temp, X_OK))
				print_cmd_error(NO_PERMIT);
			return (temp);
		}
		free(temp);
		(arg->tenv.path)++;
	}
	print_cmd_error(0);
	return (0);
}
