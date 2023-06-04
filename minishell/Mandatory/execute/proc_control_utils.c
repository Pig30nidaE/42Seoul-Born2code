/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_control_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:01:53 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/23 18:24:56 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_proc_branching_by_status(int status, int *i)
{
	if ((status == 2) && ((*i) == 0))
	{
		write(1, "\n", 1);
		(*i)++;
	}
	else if ((status == 3) && ((*i) == 0))
	{
		write(1, "Quit: 3\n", 8);
		(*i)++;
	}
}

void	pre_process_before_fork(t_box *box, int *i)
{
	box->stdin = dup(STDIN_FILENO);
	while (++(*i) < box->pipe_size)
		check_heredoc(box, box->exe[*i], *i);
	*i = -1;
	if (box->pipe_size == 1 && check_is_builtin(box->exe[0]->cmd))
	{
		change_stream(box, box->exe[0], 0);
		run_builtin(box,
			box->exe[0]->cmd, box->exe[0]->args);
		(*i)++;
	}
}

void	fork_behv_brcin_by_pid(t_box *box, int i)
{
	if (box->pid == -1)
		print_fork_error();
	else if (!(box->pid))
	{
		change_stream(box, box->exe[i], i);
		if (check_is_builtin(box->exe[i]->cmd))
			run_builtin(box,
				box->exe[i]->cmd, box->exe[i]->args);
		else
			execve(find_cmd_path(box, box->exe[i]->cmd),
				box->exe[i]->args, box->env_save);
	}
	else
		parents_process(box);
}

// void	check_path_exit(t_box *box)
// {
// 	if (!get_env_by_key(box->env, "PATH"))
// }
