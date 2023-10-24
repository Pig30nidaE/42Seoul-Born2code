/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:44:25 by sanghyol          #+#    #+#             */
/*   Updated: 2022/11/20 21:43:33 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(long long n)
{
	int			count;
	long long	num;

	count = 1;
	num = n;
	if (n < 0)
	{
		count++;
		num = -n;
	}
	while (num / 10 > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			digit;

	digit = get_digit_count((long long)n);
	str = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		num = -((long long)n);
		str[0] = '-';
	}
	else
		num = (long long)n;
	str[digit] = '\0';
	while (--digit >= 0)
	{
		if (str[digit] == '-')
			break ;
		str[digit] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
