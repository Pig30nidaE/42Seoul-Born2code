/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:07:00 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 22:43:54 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_box	*box;
	char	*shell_lv;

	(void)argc;
	(void)argv;
	box = init_box();
	box->env = set_envp(env);
	shell_lv = ft_itoa(ft_atoi(get_env_by_key(box->env, "SHLVL")) + 1);
	env_modify_value(box->env, "SHLVL", shell_lv);
	free(shell_lv);
	box->path = get_path_env(env);
	set_signal(2);
	run_prompt(box);
	unset_term();
}

char	**get_path_env(char **env)
{
	while (*env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (ft_split(*env + 5, ':'));
		env++;
	}
	return (0);
}
