/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_control_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:01:37 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:46:18 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_open_files(t_exe *exe)
{
	exe->redirect = lstfirst(exe->redirect);
	while (exe->redirect)
	{
		if (exe->redirect->type == infile)
		{
			exe->infd = open(exe->redirect->content, O_RDWR);
			exe->infile = exe->redirect->content;
		}
		if (exe->redirect->type == outfile)
		{
			exe->outfd = open(exe->redirect->content,
					O_RDWR | O_CREAT | O_TRUNC, 0644);
			exe->outfile = exe->redirect->content;
		}
		if (exe->redirect->type == append)
			exe->outfd = open(exe->redirect->content,
					O_RDWR | O_CREAT | O_APPEND, 0644);
		if (exe->redirect->next)
			exe->redirect = exe->redirect->next;
		else
			break ;
	}
}

void	check_heredoc(t_box *box, t_exe *exe, int i)
{
	char			*base_file_name;
	char			*to_open_file_name;	
	char			*tmp;

	base_file_name = "/tmp/.here_doc";
	exe->redirect = lstfirst(exe->redirect);
	while (exe->redirect)
	{
		tmp = ft_itoa(i);
		to_open_file_name = ft_strjoin_libft(base_file_name, tmp);
		free(tmp);
		if (exe->redirect->type == here_doc)
		{
			exe->infd = open(to_open_file_name, O_RDWR
					| O_CREAT | O_TRUNC, 0666);
			get_input_til_limiter(exe->infd, exe->redirect->content, box->env);
			exe->infd = open(to_open_file_name, O_RDONLY, 0644);
		}
		free(to_open_file_name);
		if (exe->redirect->next)
			exe->redirect = exe->redirect->next;
		else
			break ;
	}
	exe->redirect = lstfirst(exe->redirect);
}

void	get_input_til_limiter(int fd, char *limiter, t_env *env)
{
	char	*input;

	input = readline("> ");
	while (input && ft_strncmp(input, limiter, ft_strlen(limiter) + 1))
	{
		if (check_dollar(input))
			input = convert_dollar_heredoc(input, env);
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = readline("> ");
	}
	free(input);
	close(fd);
}

void	nopipe_to_file_stream(t_box *box, t_exe *exe)
{
	if (exe->infd && exe->outfd)
		infile_to_outfile(box, exe);
	else if (exe->infd && !(exe->outfd))
		infile_to_stdout(box, exe);
	else if (!(exe->infd) && exe->outfd)
		stdin_to_outfile(box, exe);
	else
		return ;
}

void	with_pipe_to_file_stream(t_box *box, t_exe *exe)
{
	if (exe->infd && exe->outfd)
		infile_to_outfile(box, exe);
	else if (exe->infd && !(exe->outfd))
		infile_to_pipe(box, exe);
	else if (!(exe->infd) && exe->outfd)
		pipe_to_outfile(box, exe);
	else
		return ;
}
