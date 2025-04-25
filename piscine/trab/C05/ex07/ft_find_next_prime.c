/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:00:40 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/30 19:00:42 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < (nb / 2))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	prime;

	prime = 0;
	i = 2;
	if (nb <= 1)
		return (0);
	while (nb < 2147483647 && prime == 0)
	{
		prime = ft_is_prime(nb);
		if (prime == 0)
			nb++;
	}
	return (nb);
}
/*
int	main()
{
	int	nb;

	nb = 4332;
	if (ft_find_next_prime(nb) == nb)
		printf("%d is prime", nb);
	else
		printf("the prime next to %d is %d", nb, ft_find_next_prime(nb));
}
*/
