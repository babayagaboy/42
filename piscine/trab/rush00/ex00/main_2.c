/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:14:49 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 16:14:54 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *num)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 1;
	while (num[i] != '\0')
	{
		while (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13))
			i++;
		while (num[i] == '-' || num[i] == '+')
		{
			if (num[i] == '-')
				neg *= -1;
			i++;
		}
		while (num[i] >= 48 && num[i] <= 57)
			result = result * 10 + num[i++] - 48;
		result *= neg;
		return (result);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = 5;
	y = 5;
	if (argc == 2)
	{
		write(1, "invalid dimensions.\n", 21);
		return (0);
	}
	if (argc > 2)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x <= 0 || y <= 0)
		{
			write(1, "invalid dimensions.\n", 21);
			return (0);
		}
		rush(x, y);
	}
	else
		rush(x, y);
	return (0);
}
