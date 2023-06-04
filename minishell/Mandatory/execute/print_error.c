/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:50:38 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:00:30 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_no_such_fd(char *cmd, char *path, int pipe_size, int errno)
{
	char		*join_msg;

	ft_putstr_fd("minishell: ", 2);
	join_msg = ft_strjoin_libft(cmd, ": ");
	if (cmd)
		ft_putstr_fd(join_msg, 2);
	free(join_msg);
	join_msg = ft_strjoin_libft(path, ": ");
	ft_putstr_fd(join_msg, 2);
	free(join_msg);
	no_such_fd_branching(cmd, path, pipe_size, errno);
}

void	print_fork_error(void)
{
	perror("fork error");
	exit(1);
}

void	print_pipe_error(void)
{
	perror("pipe error");
	exit(1);
}

void	print_cmd_error(char *cmd, int errno)
{
	ft_printf("minishell: ");
	ft_printf("%s: ", cmd);
	if (errno == NO_PERMIT)
		ft_putendl_fd("Permission denied", 2);
	else if (errno == PATH_ERROR)
		ft_putendl_fd("command not found", 2);
	exit(errno);
}
