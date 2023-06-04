/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:41:36 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/21 21:31:28 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_too_many_args(t_box *box, char *cmd)
{
	write(2, "minishell: ", 11);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	ft_putendl_fd("too many arguments", 2);
	if (box->pipe_size > 1)
		exit(1);
	else
		g_error_code = 1;
}

void	print_numeric_need(char *cmd, char *args)
{
	ft_printf("minishell: ");
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, args, ft_strlen(args));
	write(2, ": ", 2);
	ft_putendl_fd("numeric argument required", 2);
}

void	*print_syntax_error_null(char *err)
{
	char	*str;
	char	*tmp;

	ft_printf("minishell: ");
	str = "syntax error near unexpected token `";
	ft_putstr_fd(str, 2);
	tmp = ft_strjoin_libft(err, "'");
	ft_putendl_fd(tmp, 2);
	free(tmp);
	g_error_code = 258;
	return (NULL);
}

int	print_syntax_error_int(char *err)
{
	char	*str;
	char	*tmp;

	ft_printf("minishell: ");
	str = "syntax error near unexpected token `";
	ft_putstr_fd(str, 2);
	tmp = ft_strjoin_libft(err, "'");
	ft_putendl_fd(tmp, 2);
	free(tmp);
	g_error_code = 258;
	return (0);
}
