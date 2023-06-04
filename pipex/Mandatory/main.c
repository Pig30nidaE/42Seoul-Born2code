/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:23:02 by sanghyol          #+#    #+#             */
/*   Updated: 2023/04/12 19:46:39 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_arg	arg;

	check_argc(argc);
	arg.file.fd[0] = open(argv[1], O_RDONLY);
	arg.file.fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	get_cmd_arg(&arg, argv);
	check_env(env);
	arg.tenv.path = get_path_env(env);
	arg.tenv.env = env;
	let_fork(&arg);
	free_pipex(&arg);
}

void	free_pipex(t_arg *arg)
{
	int		i;
	int		j;
	char	**arg_arr;

	i = -1;
	j = -1;
	while ((++i) < 2)
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
