/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:37:16 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/13 14:21:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(unsigned long long nbr, int base, char type);
int	print_format(char type, va_list ap);
int	ft_printf(const char *str, ...);

#endif