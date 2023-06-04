/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:23:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 20:23:01 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_arg	arg;

	check_argc(argc);
	if (check_here_doc(&arg, argv[1]))
	{
		arg.file.fd[0] = open("/tmp/.here_doc", O_RDWR | O_CREAT | O_TRUNC,
				0666);
		get_cmd_by_gnl(arg.file.fd[0], argv[2]);
		close(arg.file.fd[0]);
		arg.file.fd[0] = open("/tmp/.here_doc", O_RDONLY, 0644);
		arg.file.fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND,
				0644);
	}
	else
	{
		arg.file.fd[0] = open(argv[1], O_RDONLY);
		arg.file.fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	get_cmd_arg(&arg, argv);
	check_env(env);
	arg.tenv.path = get_path_env(env);
	arg.tenv.env = env;
	let_fork(&arg);
	free_pipex(&arg, arg.m_size);
	unlink(".here_doc");
}

void	get_cmd_by_gnl(int fd, char *limiter)
{
	char	*gnl;

	ft_printf("%s", "pipe heredoc> ");
	gnl = get_next_line(0);
	limiter = ft_strjoin_libft(limiter, "\n");
	while (gnl && ft_strncmp(gnl, limiter, ft_strlen(limiter)))
	{
		write(fd, gnl, ft_strlen(gnl));
		ft_printf("%s", "pipe heredoc> ");
		free(gnl);
		gnl = get_next_line(0);
	}
	free(limiter);
	free(gnl);
}

void	free_pipex(t_arg *arg, int size)
{
	int		i;
	int		j;
	char	**arg_arr;

	i = -1;
	while ((++i) < size)
	{
		j = -1;
		arg_arr = arg->cmd.c_arg[i].arg_arr;
		while (arg_arr[++j])
			free(arg_arr[j]);
		free(arg->cmd.c_arg[i].arg_arr);
	}
	free(arg->cmd.c_arg);
	free(arg->cmd.cmd);
	i = -1;
	while (arg->tenv.path[++i])
		free(arg->tenv.path[i]);
	free(arg->tenv.path);
}
