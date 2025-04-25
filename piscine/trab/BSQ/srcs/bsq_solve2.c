/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solve2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:56:45 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:56:48 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

void	fill_dp_cell(int **dp, char **matrix, t_data *data, t_square *max)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size_matrix_y)
	{
		j = -1;
		while (++j < data->size_matrix_x)
		{
			if (matrix[i][j] == data->obst)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1],
						dp[i - 1][j - 1]);
			update_max_square(dp[i][j], i, j, max);
		}
	}
}

void	mark_square(char **matrix, t_data *data, t_square *max)
{
	int	i;
	int	j;

	i = max->row - max->size + 1;
	while (i <= max->row)
	{
		j = max->col - max->size + 1;
		while (j <= max->col)
			matrix[i][j++] = data->full;
		i++;
	}
}

void	solve(char **matrix, t_data *data)
{
	int			**dp;
	t_square	max;

	max.size = 0;
	dp = alloc_dp_matrix(data->size_matrix_y, data->size_matrix_x);
	if (!dp)
		return ;
	fill_dp_cell(dp, matrix, data, &max);
	mark_square(matrix, data, &max);
	free_dp_matrix(dp, data->size_matrix_y);
}
