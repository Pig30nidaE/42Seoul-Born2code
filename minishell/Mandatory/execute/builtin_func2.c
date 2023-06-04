/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:35:19 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:42:43 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **str, int pipe_size)
{
	int	i;
	int	echo_flag;

	i = -1;
	if (!str[0])
	{
		ft_printf("\n");
		return ;
	}
	echo_flag = is_echo_option_exist(str[0]);
	i += echo_flag;
	while (str[(++i) + 1])
		ft_printf("%s ", str[i]);
	if (str[i])
		ft_printf("%s", str[i]);
	if (!echo_flag)
		ft_printf("\n");
	if (pipe_size != 1)
		exit(0);
	else
		g_error_code = 0;
}

int	is_echo_option_exist(char *option)
{
	size_t	i;

	i = 0;
	if (!option)
		return (0);
	if (option[i] != '-')
		return (0);
	while ((++i) < ft_strlen(option))
	{
		if (option[i] != 'n')
			return (0);
	}
	return (1);
}

void	ft_export(t_box *box, char **args)
{
	int		i;

	i = 0;
	if (args[1])
		export_add_env(box->env, args);
	else
		export_print_env(box->env);
}

void	export_add_env(t_env *env, char **args)
{
	int		equal_index;
	int		i;
	char	*value;

	i = 0;
	while (args[++i])
	{
		equal_index = ft_strchr_index(args[i], '=');
		value = get_value(args[i], equal_index + 1);
		if (equal_index)
			expt_add_behv_is_eq(env, args, equal_index, i);
		else
			expt_add_behv_isnt_eq(env, args, i);
	}
}

void	export_print_env(t_env *env)
{
	int	i;
	int	env_len;

	env_len = env_size(env);
	i = 0;
	while ((++i) <= env_len)
	{
		env = envfirst(env);
		while (env)
		{
			if (env->order == i)
			{
				if (env->value)
					ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
				else
					ft_printf("declare -x %s\n", env->key);
				break ;
			}
			if (env->next)
				env = env->next;
			else
				break ;
		}
	}
	expt_prt_added_env(env);
}
