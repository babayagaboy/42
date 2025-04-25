/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:41:48 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 19:41:57 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_special_line(int a)
{
	ft_putchar('o');
	a -= 2;
	while (a > 0)
	{
		a--;
		ft_putchar('-');
	}
	if (a == 0)
		ft_putchar('o');
	return (0);
}

int	ft_every_line(int a)
{
	while (a > 0)
	{
		ft_putchar('|');
		a -= 2;
		while (a > 0)
		{
			a--;
			ft_putchar(' ');
		}
		if (a == 0)
			ft_putchar('|');
	}
	return (0);
}

void	rush(int x, int y)
{
	int	a;
	int	b;
	int	special_line;

	special_line = 1;
	a = x;
	b = y;
	while (b > 0)
	{
		while (a > 0)
		{
			if (special_line == 1)
			{
				a = ft_special_line(a);
				special_line = 0;
			}
			else
				a = ft_every_line(a);
		}
		a = x;
		ft_putchar('\n');
		b--;
		if (b == 1)
			special_line = 1;
	}
}
