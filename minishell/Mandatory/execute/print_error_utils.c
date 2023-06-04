/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:57:49 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:31:21 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	no_such_fd_branching(char *cmd, char *path, int pipe_size, int errno)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) < 0)
		ft_putendl_fd("No such file or directory", 2);
	else if (S_ISDIR(statbuf.st_mode))
		ft_putendl_fd("is a directory", 2);
	else
	{
		if (cmd)
			ft_putendl_fd("Not a directory", 2);
		else
			ft_putendl_fd("No such file or directory", 2);
	}
	if (pipe_size == 1 && check_is_builtin(cmd))
		g_error_code = errno;
	else
		exit(errno);
}
