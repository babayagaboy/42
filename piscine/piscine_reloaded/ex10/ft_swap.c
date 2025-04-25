/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:10:38 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/03 16:10:39 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int	main()
{
	int	a;
	int	b;

	a = 10;
	b = 42;
	printf("a: %i\nb: %i\n", a, b);
	ft_swap(&a, &b);
	printf("a: %i\nb: %i\n", a, b);
	return (0);
}
*/
