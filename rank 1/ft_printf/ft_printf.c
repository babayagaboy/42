/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:29:31 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/24 16:29:32 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return(write(1, &c, 1));
}

int	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += print_char(str[i]);
	return(i);
}

int	print_digit(long nbr, int base, char type)
{
	int len;
	char *base_char;

	if (type == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	len = 0;
	if (nbr < 0)
	{
		print_char('-');
		return(print_digit(-nbr, base, type) + 1); //+1 for the menos
	}
	else if (nbr < base)
		return(print_char(base_char[nbr]));
	else
	{
		len = print_digit(nbr / base, base, type);
		return(len + print_digit(nbr % base, base, type));
	}
}

int	print_format(char type, va_list ap)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += print_char(va_arg(ap, int));
	if (type == 's')
		len += print_str(va_arg(ap, char *));
	if (type == 'd' || type == 'i')
		len += print_digit((long) va_arg(ap, int), 10, type);
	if (type == 'x')
		len += print_digit((long) va_arg(ap, unsigned int), 16, type);
	if (type == 'X')
		len += print_digit((long) va_arg(ap, unsigned int), 16, type);
	/*	if (type == 'p')
		len += print_p(va_arg(ap, void *));
	if (type == 'u')
		len += print_char(va_arg(ap, int)); */
	if (type == '%')
		len += print_char('%');
	else
		len += write(1, &type, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int len;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if(*str == '%')
			len += print_format(*(++str), ap);
		else
			len += print_char(*str);
		str++;
	}
	va_end(ap);
	return (len);
}

int main()
{
	int len = ft_printf("Hello %s", "Hugo");
	ft_printf(", and this string has %d char\n", len);

	len = printf("Hello %s", "Hugo");
	printf(", and this string has %d char\n", len);
}