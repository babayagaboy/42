/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:50:20 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/22 17:24:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_putchar(char a1, char a2, char b1, char b2)
{
	if (((a1 * 10) + a2) < ((b1 * 10) + b2))
	{
		write(1, &a1, 1);
		write(1, &a2, 1);
		write(1, " ", 1);
		write(1, &b1, 1);
		write(1, &b2, 1);
		if (a1 != '9' || a2 != '8')
			write(1, ", ", 2);
	}
	return (1);
}

void	ft_print_comb2(void)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	a1 = 0;
	while (a1 <= 9)
	{
		a2 = 0;
		while (a2 <= 9)
		{
			b1 = 0;
			while (b1 <= 9)
			{
				b2 = 0;
				while (b2 <= 9)
					b2 += ft_putchar(a1 + '0', a2 + '0', b1 + '0', b2 + '0');
				b1++;
			}
			a2++;
		}
		a1++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
