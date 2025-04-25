/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:56:12 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/04 11:56:13 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	range_len;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	range_len = max - min;
	range = (int *)malloc(range_len * sizeof(int));
	if (!range)
		return (NULL);
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int	main()
{
	int	min;
	int	max;

	min = 1;
	max = 0;

	int	*range = ft_range(min, max);
	if (range != NULL) 
	{
		for (int i = 0; i < max - min; i++) 
		{
			printf("%d ", range[i]);
		}
		free(range);
	}
	else
		printf("malloc error");
	return (0);
}
*/
