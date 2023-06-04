/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:03:40 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 20:40:59 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_cmd_path_exist(char *cmd, char *str, int pipe_size)
{
	struct stat	statbuf;

	if (!access(str, F_OK))
	{
		if (access(str, X_OK))
			print_cmd_error(cmd, NO_PERMIT);
		if (stat(str, &statbuf) < 0)
			exit(1);
		if (S_ISDIR(statbuf.st_mode))
			print_no_such_fd(0, str, pipe_size, NO_PERMIT);
		return (str);
	}
	else
		print_no_such_fd(0, str, pipe_size, PATH_ERROR);
	return (0);
}

void	check_fd(char *file_name, int fd, int pipe_size)
{
	if (fd < 0)
		print_no_such_fd(0, file_name, pipe_size, GENERAL_ERROR);
}
