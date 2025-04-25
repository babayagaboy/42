/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:55:04 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:55:08 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int	**alloc_dp_matrix(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		dp[i] = malloc(sizeof(int) * cols);
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (NULL);
		}
	}
	return (dp);
}

void	free_dp_matrix(int **dp, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(dp[i]);
	free(dp);
}

void	update_max_square(int value, int i, int j, t_square *max)
{
	if (value > max->size)
	{
		max->size = value;
		max->row = i;
		max->col = j;
	}
}
