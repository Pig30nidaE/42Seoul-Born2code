/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:32:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:45:03 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_fd_error(void)
{
	ft_putendl_fd("fd error: no such file or directory", 2);
	exit(1);
}

void	print_argc_error(void)
{
	ft_putendl_fd("argc error: invalid argument", 2);
	exit(1);
}

void	print_cmd_error(int errno)
{
	if (errno)
	{
		if (errno == NO_SUCH_FD)
			perror("command error: ");
		else
			ft_putendl_fd("command error: permission denied", 2);
	}
	else
		ft_putendl_fd("command error: not found", 2);
	exit(1);
}

void	print_env_error(void)
{
	perror("env error");
	exit(1);
}

void	print_pipe_error(void)
{
	perror("pipe error");
	exit(1);
}
