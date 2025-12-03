/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:29:31 by hgutterr          #+#    #+#             */
/*   Updated: 2025/12/03 11:13:20 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_char(int c)
{
	return (write(1, &c, 1));
}

int	p_str(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += p_char(str[i]);
	return (i);
}

int	p_digit(unsigned long long nbr, int base, char type)
{
	char	*base_char;

	base_char = "0123456789abcdef";
	if (type == 'X')
		base_char = "0123456789ABCDEF";
	if (type == 'u')
		base = 10;
	if (nbr < (unsigned long long) base)
		return (p_char(base_char[nbr]));
	else
		return (p_digit(nbr / base, base, type)
			+ p_char(base_char[nbr % base]));
}


int	p_format(char type, va_list ap)
{
	long		nbr;
	void		*p;

	if (type == 'c')
		return (p_char(va_arg(ap, int)));
	else if (type == 's')
		return (p_str(va_arg(ap, char *)));
	else if (type == 'd' || type == 'i')
	{
		nbr = va_arg(ap, int);
		if (nbr < 0)
			return (p_char('-') + p_digit(-(long long)nbr, 10, type));
		return (p_digit(nbr, 10, type));
	}
	else if (type == 'x' || type == 'X' || type == 'u')
		return (p_digit((long) va_arg(ap, unsigned int), 16, type));
	else if (type == 'p')
	{
		p = va_arg(ap, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (p_str("0x") + p_digit((unsigned long long) p, 16, type));
	}
	return (p_char('%'));
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
			len += p_format(*(++str), ap);
		else
			len += p_char(*str);
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