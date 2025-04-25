/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:00:01 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/04 13:00:03 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_range_len(int min, int max)
{
	int	i;

	i = 0;
	while (min < max)
	{
		min++;
		i++;
	}
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	range_len;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	range_len = ft_range_len(min, max);
	ptr = (int *)malloc(range_len * sizeof(int));
	if (!ptr)
		return (-1);
	while (min + i < max)
	{
		ptr[i] = min + i;
		i++;
	}
	*range = ptr;
	return (range_len);
}
/*
int	main()
{
	int	min;
	int	max;
	int	*range;
	int	range_len;

	min = 10;
	max = 20;

	range_len = ft_ultimate_range(&range, min, max);
	if (range != NULL) 
	{
		for (int i = 0; i < max - min; i++) 
		{
			printf("%d ", range[i]);
		}
		printf("\nlen = %d", range_len);
		free(range);
	}
	else
		printf("malloc error");
	return (0);
}*/
