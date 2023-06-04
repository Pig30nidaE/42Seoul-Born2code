/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_flow_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:03:38 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/10 21:26:40 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	pipe_to_pipe(t_arg *arg)
{
	dup2(arg->pipe_fd[PIPE_STDIN], STDOUT_FILENO);
	close(arg->pipe_fd[PIPE_STDOUT]);
	close(arg->pipe_fd[PIPE_STDIN]);
}

void	pipe_to_outfile(t_arg *arg)
{
	close(arg->pipe_fd[PIPE_STDIN]);
	dup2(arg->file.fd[OUTFILE], STDOUT_FILENO);
	close(arg->pipe_fd[PIPE_STDOUT]);
	close(arg->file.fd[OUTFILE]);
}
