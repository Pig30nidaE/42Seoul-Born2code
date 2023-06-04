/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:40:30 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:40:35 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	current_path[1024];

	if (getcwd(current_path, 1024))
		ft_printf("%s\n", current_path);
}

void	ft_cd(t_env *env, char **args, int pipe_size)
{
	char	*old;
	char	*path;
	char	current_path[1024];

	old = getcwd(current_path, 1024);
	if (!args[1])
		path = get_env_by_key(env, "HOME");
	else
		path = args[1];
	if (chdir(path))
		print_no_such_fd("cd", path, pipe_size, GENERAL_ERROR);
	else
	{
		env_modify_value(env, "OLDPWD", old);
		env_modify_value(env, "PWD", getcwd(current_path, 1024));
		if (pipe_size != 1)
			exit(0);
		else
			g_error_code = 0;
	}
}

void	ft_env(t_env *env, int pipe_size)
{
	env = envfirst(env);
	while (env)
	{
		if (env->key && env->value)
			ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	if (pipe_size != 1)
		exit(0);
}

void	ft_unset(t_env *env, char **args)
{
	int	i;

	if (!(args[1]))
		return ;
	i = 0;
	while (args[++i])
	{
		while (env && env->key)
		{
			if (!ft_strncmp(env->key, args[i], ft_strlen(env->key) + 1))
			{
				envdel(env);
				break ;
			}
			env = env->next;
		}
	}
	return ;
}

void	ft_exit(t_box *box, char **args)
{
	if (box->pipe_size <= 1)
		ft_printf("exit\n");
	if (args[1])
		exit_behavior_is_args(box, args);
	else
	{
		g_error_code = 0;
		heredoc_unlink();
		unset_term();
		exit(0);
	}
}
