/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:05:10 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/23 18:23:10 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_unlink(void)
{
	int		i;
	char	*base_file_name;
	char	*to_open_file_name;
	char	*tmp;

	i = 0;
	base_file_name = "/tmp/.here_doc";
	while (1)
	{
		tmp = ft_itoa(i);
		to_open_file_name = ft_strjoin_libft(base_file_name, tmp);
		free(tmp);
		if (unlink(to_open_file_name) == -1)
		{
			free(to_open_file_name);
			return ;
		}
		free(to_open_file_name);
		i++;
	}
}

int	is_white_space(char *input)
{
	char	*str;

	str = input;
	if (*input == 0)
		return (0);
	else
	{
		while (*str)
		{
			if (*str != ' ')
				return (1);
			str++;
		}
		return (0);
	}
}

void	run_prompt(t_box *box)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (input && is_white_space(input))
		{
			if (!parsing(input, box))
			{
				let_fork(box);
				set_signal(2);
			}
		}
		else if (!input)
		{
			printf("\033[Aminishell$ exit\n");
			break ;
		}
		free_box_partial(&box);
		add_history(input);
		free(input);
	}
	free(input);
	heredoc_unlink();
	free_box_all(&box);
}

void	run_builtin(t_box *box, char *cmd, char **args)
{
	if (!ft_strncmp(cmd, "echo\0", ft_strlen(cmd) + 1))
		ft_echo(&args[1], box->pipe_size);
	else if (!ft_strncmp(cmd, "cd\0", ft_strlen(cmd) + 1))
		ft_cd(box->env, args, box->pipe_size);
	else if (!ft_strncmp(cmd, "pwd\0", ft_strlen(cmd) + 1))
		ft_pwd();
	else if (!ft_strncmp(cmd, "export\0", ft_strlen(cmd) + 1))
		ft_export(box, args);
	else if (!ft_strncmp(cmd, "unset\0", ft_strlen(cmd) + 1))
		ft_unset(box->env, args);
	else if (!ft_strncmp(cmd, "env\0", ft_strlen(cmd) + 1))
		ft_env(box->env, box->pipe_size);
	else if (!ft_strncmp(cmd, "exit\0", ft_strlen(cmd) + 1))
		ft_exit(box, args);
}

int	check_is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	else if (!ft_strncmp(cmd, "echo\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "cd\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "pwd\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "export\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "unset\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "env\0", ft_strlen(cmd) + 1))
		return (1);
	else if (!ft_strncmp(cmd, "exit\0", ft_strlen(cmd) + 1))
		return (1);
	else
		return (0);
}
