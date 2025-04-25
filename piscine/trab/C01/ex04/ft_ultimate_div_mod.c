/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:09:20 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 18:09:21 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = temp / *b;
	*b = temp % *b;
}

/*
int	main(void)
{
	int	num1;
	int	num2;

	num1 = 42;
	num2 = 10;

	printf("before\nnum1 = %d\nnum2 = %d\n\n" , num1, num2);

	ft_ultimate_div_mod(&num1, &num2);
	
	printf("after\nnum1 = %d\nnum2 = %d\n" , num1, num2);
}
*/
