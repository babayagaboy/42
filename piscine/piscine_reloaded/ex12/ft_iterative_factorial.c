/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:15:04 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/03 16:15:05 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	unsigned int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	if (result < 0)
		return (0);
	return (result);
}
/*
int	main()
{
	int	nb;

	nb = 5;
	printf("%d! = %d\n", nb , ft_iterative_factorial(nb));
	printf("%d! = %d\n", nb , ft_iterative_factorial(22));
	printf("%d! = %d\n", nb , ft_iterative_factorial(-97));
	printf("%d! = %d\n", nb , ft_iterative_factorial(10));
	printf("%d! = %d\n", nb , ft_iterative_factorial(7));
	printf("%d! = %d\n", nb , ft_iterative_factorial(13));
}
*/
