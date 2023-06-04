/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:12:13 by sanghyol          #+#    #+#             */
/*   Updated: 2023/05/20 21:30:14 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ascii_cmp(char *s1, char *s2)
{
	int	i;
	int	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (!s1[i])
			return (-1);
		if (!s2[j])
			return (1);
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	return (0);
}
