/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_control2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:23:51 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 20:41:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	infile_to_stdout(t_box *box, t_exe *exe)
{
	check_fd(exe->infile, exe->infd, box->pipe_size);
	close(box->pipe_fd[PIPE_STDOUT]);
	dup2(exe->infd, STDIN_FILENO);
	close(exe->infd);
	close(box->pipe_fd[PIPE_STDIN]);
}

void	stdin_to_outfile(t_box *box, t_exe *exe)
{
	close(box->pipe_fd[PIPE_STDIN]);
	dup2(exe->outfd, STDOUT_FILENO);
	close(exe->outfd);
	close(box->pipe_fd[PIPE_STDOUT]);
}

void	pipe_to_stdout(t_box *box)
{
	close(box->pipe_fd[PIPE_STDIN]);
	close(box->pipe_fd[PIPE_STDOUT]);
}

void	stdin_to_pipe(t_box *box)
{
	close(box->pipe_fd[PIPE_STDOUT]);
	dup2(box->pipe_fd[PIPE_STDIN], STDOUT_FILENO);
	close(box->pipe_fd[PIPE_STDIN]);
}
