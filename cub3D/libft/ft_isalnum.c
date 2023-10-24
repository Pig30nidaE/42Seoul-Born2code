/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:13 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/09 20:20:06 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isalpha_clone(int c);
static	int	ft_isdigit_clone(int c);

static	int	ft_isalpha_clone(int c)
{
	if ((97 <= c && c <= 122) || (65 <= c && c <= 90))
		return (1);
	return (0);
}

static	int	ft_isdigit_clone(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha_clone(c) || ft_isdigit_clone(c))
		return (1);
	return (0);
}
