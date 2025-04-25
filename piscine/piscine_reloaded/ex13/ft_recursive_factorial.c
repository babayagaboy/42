/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:32:10 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/07 18:32:12 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 0)
		result *= nb * ft_recursive_factorial(nb - 1);
	if (result < 0)
		return (0);
	return (result);
}
/*
int	main()
{
	int	nb;

	nb = 22;
	printf("%d! = %d\n", nb ,ft_recursive_factorial(nb));
}
*/
