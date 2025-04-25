/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:40 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/28 15:20:46 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	int	x;

	if (argc > 2)
	{
		printf("invalid input.\n");
		return (0);
	}
	if (argc == 2)
	{
		x = ft_atoi(argv[1]);
		printf("the number is %d", x);
		
	}
	else
		printf("invalid input.\n");
	return (0);
}

