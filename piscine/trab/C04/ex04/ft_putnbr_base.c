/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:11:17 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/28 16:11:18 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_base_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		while (base[i] != base[j])
		{
			j++;
		}
		if (base[i] == base[j] && i != j)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_leng;
	int	base_symbol;

	base_symbol = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	base_leng = ft_is_base_correct(base);
	if (base_leng)
	{
		if (nbr >= base_leng)
		{
			ft_putnbr_base(nbr / base_leng, base);
		}
		base_symbol = nbr % base_leng;
	}
	else
		return ;
	ft_putchar(base[base_symbol]);
}
/*
int	main()
{
	int	nbr;
	char	*base;

	nbr = 56457;
	base = "0";

	ft_putnbr_base(nbr, base);
}
*/
