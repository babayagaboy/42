/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:35 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 18:30:37 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	size -= 1;
	i = 0;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}
/*
int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size;

	size = 9;
	
	printf("original = ");
	for(int i = 0; i < size; i++) {
        	printf("%d ", tab[i]);
    	}
    	
	ft_rev_int_tab(tab, size);
    	
    	printf("\n");
    	printf("reversed = ");
	for(int i = 0; i < size; i++) {
        	printf("%d ", tab[i]);
    	}
}
*/
