/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:53:04 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:53:06 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

char	**alloc_matrix_rows(int rows)
{
	char	**matrix;

	matrix = malloc(sizeof(char *) * rows);
	if (!matrix)
		return (NULL);
	return (matrix);
}

int	alloc_matrix_cols(char **matrix, int rows, int cols)
{
	int	i;

	i = -1;
	while (++i < rows)
	{
		matrix[i] = malloc(sizeof(char) * cols);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (0);
		}
	}
	return (1);
}

char	**alloc_matrix(t_data *data)
{
	char	**matrix;

	matrix = alloc_matrix_rows(data->size_matrix_y);
	if (!matrix)
		return (NULL);
	if (!alloc_matrix_cols(matrix, data->size_matrix_y, data->size_matrix_x))
		return (NULL);
	return (matrix);
}

int	read_map_line(int fd, char *line, int *len)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			*len = i;
			return (1);
		}
		line[i++] = c;
	}
	*len = i;
	return (i > 0);
}

void	copy_line_to_matrix(char **matrix, char *line, int row, int len)
{
	int	j;

	j = -1;
	while (++j < len)
		matrix[row][j] = line[j];
}
