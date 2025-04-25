/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:21:55 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/23 13:21:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char *arr, int neg)
{
	int	i;

	i = 0;
	if (neg == -1)
		write(1, "-", 1);
	while (arr[i] != '\0')
	{
		write(1, &arr[i], 1);
		i++;
	}
}

int	ft_find_index(int nb)
{
	int	index;

	index = 1;
	while (nb >= 9)
	{
		nb /= 10;
		index++;
	}
	return (index);
}

int	ft_is_negative(int nb)
{
	if (nb < 0)
		return (-1);
	else
		return (1);
}

void	ft_putnbr(int nb)
{
	int		neg;
	int		i;
	char	arr[10];

	neg = ft_is_negative(nb);
	if (neg == -1)
		nb *= -1;
	i = ft_find_index(nb);
	arr[i--] = '\0';
	while (nb >= 9)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	arr[0] = nb + '0';
	ft_putchar(arr, neg);
}

/*
int	main()
{
	int num;

	num = -1;
	ft_putnbr(num);
	return (0);
}
*/
