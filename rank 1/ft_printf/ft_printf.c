/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:29:31 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/12 16:56:39 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += print_char(str[i]);
	return (i);
}

int	print_digit(long nbr, int base, char type)
{
	int		len;
	char	*base_char;

	len = 0;
	if (type == 'u')
		nbr = (nbr) * (nbr > 0) - (nbr) * (nbr < 0);
	base_char = "0123456789abcdef";
	if (type == 'X')
		base_char = "0123456789ABCDEF";
	if (nbr < 0)
		return (print_char('-'), print_digit(-nbr, base, type) + 1);
	else if (nbr < base)
		return (print_char(base_char[nbr]));
	else
	{
		len = print_digit(nbr / base, base, type);
		return (len + print_digit(nbr % base, base, type));
	}
}

int	print_format(char type, va_list ap)
{
	int		len;
	void	*p;

	len = 0;
	if (type == 'c')
		len += print_char(va_arg(ap, int));
	else if (type == 's')
		len += print_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		len += print_digit((long) va_arg(ap, int), 10, type);
	else if (type == 'x' || type == 'X')
		len += print_digit((long) va_arg(ap, unsigned int), 16, type);
	else if (type == 'p')
	{
		p = va_arg(ap, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		len += print_str("0x");
		len += print_digit((unsigned long long) p, 16, type);
	}
	else if (type == 'u')
		len += print_digit(va_arg(ap, unsigned int), 10, type);
	else
		len += print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;

	if (!str)
		return (-1);
	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += print_format(*(++str), ap);
		else
			len += print_char(*str);
		str++;
	}
	va_end(ap);
	return (len);
}

/* int main()
{
	int len = ft_printf("Hello %%\n");
	ft_printf("string has %d char\n", len);

	len = printf("Hello %%\n");
	printf("string has %d char\n", len);

	unsigned int a = -52;
	char *p = "h";
	len = printf("%d -> %x -> %X -> %u; %p\n", -52, -52, -52, a, p);
	printf("len = %d\n", len);
	len = ft_printf("%d -> %x -> %X -> %u; %p\n", -52, -52, -52, a, p);
	printf("len = %d\n", len);

	char *s1 = NULL;
	len = printf("%s\n", s1);
	printf("len = %d\n", len);
	char *s2 = NULL;
	len = ft_printf("%s\n", s2);
	printf("len = %d\n", len);


	char *p1 = NULL;
	len = printf("%p -> %p\n", p1, p);
	printf("len = %d\n", len);
	char *p2 = NULL;
	len = ft_printf("%p -> %p\n", p2, p);
	printf("len = %d\n", len);
} */