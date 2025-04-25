/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 17:41:45 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int	main(void)
{
	int num1;
	int num2;
	
	num1 = 42;
	num2 = 69;
	
	printf("num1 = %d\nnum2 = %d\n\n", num1, num2);
	
	ft_swap(&num1, &num2);
	
	printf("num1 = %d\nnum2 = %d\n", num1, num2);
}
*/
