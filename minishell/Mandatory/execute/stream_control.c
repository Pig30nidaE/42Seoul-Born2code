/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:45:58 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/23 17:01:33 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parents_process(t_box *box)
{
	set_signal(0);
	dup2(box->pipe_fd[PIPE_STDOUT], STDIN_FILENO);
	close(box->pipe_fd[PIPE_STDIN]);
	close(box->pipe_fd[PIPE_STDOUT]);
}

void	infile_to_outfile(t_box *box, t_exe *exe)
{
	check_fd(exe->infile, exe->infd, box->pipe_size);
	check_fd(exe->outfile, exe->outfd, box->pipe_size);
	close(box->pipe_fd[PIPE_STDIN]);
	close(box->pipe_fd[PIPE_STDOUT]);
	dup2(exe->infd, STDIN_FILENO);
	dup2(exe->outfd, STDOUT_FILENO);
}

void	infile_to_pipe(t_box *box, t_exe *exe)
{
	check_fd(exe->infile, exe->infd, box->pipe_size);
	close(box->pipe_fd[PIPE_STDOUT]);
	dup2(exe->infd, STDIN_FILENO);
	dup2(box->pipe_fd[PIPE_STDIN], STDOUT_FILENO);
	close(exe->infd);
	close(box->pipe_fd[PIPE_STDIN]);
}

void	pipe_to_pipe(t_box *box)
{
	dup2(box->pipe_fd[PIPE_STDIN], STDOUT_FILENO);
	close(box->pipe_fd[PIPE_STDOUT]);
	close(box->pipe_fd[PIPE_STDIN]);
}

void	pipe_to_outfile(t_box *box, t_exe *exe)
{
	close(box->pipe_fd[PIPE_STDIN]);
	dup2(exe->outfd, STDOUT_FILENO);
	close(exe->outfd);
	close(box->pipe_fd[PIPE_STDOUT]);
}
