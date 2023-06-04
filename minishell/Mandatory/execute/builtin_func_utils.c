/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:43:49 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:30:23 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_behavior_is_args(t_box *box, char **args)
{
	if (ft_isstring(args[1]))
	{
		if (args[2])
			print_too_many_args(box, "exit");
		else
		{
			g_error_code = ft_atoi(args[1]);
			if (g_error_code >= 256)
				g_error_code %= 256;
			heredoc_unlink();
			exit(g_error_code);
		}
	}
	else
	{
		print_numeric_need("exit", args[1]);
		g_error_code = 255;
		heredoc_unlink();
		exit(255);
	}
}

void	expt_add_behv_is_eq(t_env *env, char **args, int equal_index, int i)
{
	char	*key;
	char	*value;

	key = get_key(args[i], equal_index);
	value = get_value(args[i], equal_index + 1);
	if (!is_key_exist(env, key))
		env_addback(env, key, value);
	else
	{
		env_modify_value(env, key, value);
		free(value);
		free(key);
	}
}

void	expt_add_behv_isnt_eq(t_env *env, char **args, int i)
{
	char	*key;

	key = get_key(args[i], ft_strlen(args[i]));
	if (!is_key_exist(env, key))
		env_addback(env, key, NULL);
}

void	expt_prt_added_env(t_env *env)
{
	env = envfirst(env);
	while (!(env->built_last_env_flag))
		env = env->next;
	if (env->next)
	{
		env = env->next;
		while (env)
		{
			if (env->value)
				ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
			else
				ft_printf("declare -x %s\n", env->key);
			if (env->next)
				env = env->next;
			else
				break ;
		}
	}
}
