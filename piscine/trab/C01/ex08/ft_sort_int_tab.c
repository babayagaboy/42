/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:06:12 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/25 22:06:13 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	correct;
	int	original_size;

	original_size = size - 1;
	correct = 0;
	size -= 1;
	i = 0;
	while (correct == 0)
	{
		correct = 1;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				correct = 0;
			}
			i++;
		}
		i = 0;
	}
}


int	main(void)
{
	int	tab[] = {7, 3, 8, 6, 1, 3, 4, 2, 9, 5};
	int	size = 10;
	
	printf("size = %d\n", size);

	printf("original = ");
	for(int i = 0; i < size; i++) {
        	printf("%d ", tab[i]);
    	}
    	
	ft_sort_int_tab(tab, size);
    	
    	printf("\n");
    	printf("organised = ");
	for(int i = 0; i < size; i++) {
        	printf("%d ", tab[i]);
    	}
}

