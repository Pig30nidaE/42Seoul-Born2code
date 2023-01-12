/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyol <sanghyol@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:41:05 by sanghyol          #+#    #+#             */
/*   Updated: 2023/01/08 21:22:57 by sanghyol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			format_replace(va_list ap, const char *format);
int			type_check(va_list ap, char specifier, int *i);
int			ft_putnbr(int n, int *i);
int			ft_putchr(char c, int *i);
int			ft_print_str(char *str, int *count);
int			ft_print_lowerhex(unsigned int num, int *count);
int			ft_print_upperhex(unsigned int num, int *count);
int			ft_print_hex(unsigned int num, int *count, char specifier);
int			ft_print_memory(unsigned long long addr, int *count);
int			ft_unputnbr(unsigned int n, int *count);

#endif