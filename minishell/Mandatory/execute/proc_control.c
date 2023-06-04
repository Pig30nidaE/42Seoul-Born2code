/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   proc_control.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: sanghyol <sanghyol@student.42seoul.kr>	 +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/04/28 00:13:51 by sanghyol	  #+#	#+#	 */
/*   Updated: 2023/05/20 16:01:11 by sanghyol	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../minishell.h"

void	let_fork(t_box *box)
{
	int	i;

	i = -1;
	pre_process_before_fork(box, &i);
	while ((++i) < box->pipe_size)
	{		
		if (pipe(box->pipe_fd) == -1)
			print_pipe_error();
		set_signal(1);
		box->pid = fork();
		fork_behv_brcin_by_pid(box, i);
	}
	wait_process(box->pid);
	dup2(box->stdin, STDIN_FILENO);
}

void	wait_process(pid_t pid)
{
	int		status;
	pid_t	wait_pid;
	int		i;

	i = 0;
	wait_pid = 0;
	while (wait_pid != -1)
	{
		wait_pid = wait(&status);
		if (wait_pid == -1)
			break ;
		if (wait_pid == pid)
		{
			if (WIFEXITED(status))
			{
				g_error_code = WEXITSTATUS(status);
				if (g_error_code >= 256)
					g_error_code /= 256;
			}
		}
		wait_proc_branching_by_status(status, &i);
	}
}

char	*find_cmd_path(t_box *box, char *cmd)
{
	char		*tmp;
	char		*temp;

	if (!ft_strncmp(&cmd[0], "/", 1) || ft_strchr(cmd, '/'))
		return (check_cmd_path_exist(cmd, cmd, box->pipe_size));
	while (*(box->path))
	{
		tmp = ft_strjoin_libft("/", cmd);
		temp = ft_strjoin_libft(get_env_by_key(box->env, "PATH"), tmp);
		free(tmp);
		if (!access(temp, F_OK))
		{
			if (access(temp, X_OK))
				print_cmd_error(cmd, NO_PERMIT);
			return (temp);
		}
		free(temp);
		(box->path)++;
	}
	print_cmd_error(cmd, PATH_ERROR);
	return (0);
}

void	change_stream(t_box *box, t_exe *exe, int i)
{
	redirect_open_files(exe);
	if (box->pipe_size > 1)
	{
		if (i == 0)
			stdin_to_pipe(box);
		else if (i + 1 == box->pipe_size)
			pipe_to_stdout(box);
		else
			pipe_to_pipe(box);
		with_pipe_to_file_stream(box, exe);
	}
	else
		nopipe_to_file_stream(box, exe);
	if (!(exe->cmd))
		exit(g_error_code);
}
