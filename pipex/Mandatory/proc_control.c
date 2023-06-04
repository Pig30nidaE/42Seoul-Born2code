/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:31 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:46:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	let_fork(t_arg *arg)
{
	int	count;

	count = -1;
	while ((++count) < 2)
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
			else
				pipe_to_outfile(arg);
			execve(find_cmd_path(*arg, arg->cmd.cmd[count]),
				arg->cmd.c_arg[count].arg_arr, arg->tenv.path);
		}
		else
			parents_process(arg);
	}
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}

void	parents_process(t_arg *arg)
{
	dup2(arg->pipe_fd[PIPE_STDOUT], STDIN_FILENO);
	close(arg->pipe_fd[PIPE_STDIN]);
	close(arg->pipe_fd[PIPE_STDOUT]);
}

void	infile_to_pipe(t_arg *arg, int count)
{
	check_fd(arg->file.fd[count]);
	close(arg->pipe_fd[PIPE_STDOUT]);
	dup2(arg->file.fd[INFILE], STDIN_FILENO);
	dup2(arg->pipe_fd[PIPE_STDIN], STDOUT_FILENO);
	close(arg->file.fd[INFILE]);
	close(arg->pipe_fd[PIPE_STDIN]);
}

void	pipe_to_outfile(t_arg *arg)
{
	close(arg->pipe_fd[PIPE_STDIN]);
	dup2(arg->file.fd[OUTFILE], STDOUT_FILENO);
	close(arg->pipe_fd[PIPE_STDOUT]);
	close(arg->file.fd[OUTFILE]);
}

char	*find_cmd_path(t_arg arg, char *cmd)
{
	char	*temp;

	if (!ft_strncmp(ft_substr(cmd, 0, 1), "/", 1) || ft_strchr(cmd, '/'))
		return (check_cmd_path_exist(cmd));
	while (*(arg.tenv.path))
	{
		temp = ft_strjoin_libft("/", cmd);
		temp = ft_strjoin_libft(*(arg.tenv.path), temp);
		if (!access(temp, F_OK))
		{
			if (access(temp, X_OK))
				print_cmd_error(NO_PERMIT);
			return (temp);
		}
		free(temp);
		arg.tenv.path++;
	}
	print_cmd_error(0);
	return (0);
}
