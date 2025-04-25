/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:53:54 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:53:55 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

char	**read_first_line(int fd, t_data *data, char *line)
{
	int		line_len;
	char	**matrix;

	if (!read_map_line(fd, line, &line_len))
		return (NULL);
	data->size_matrix_x = line_len;
	if (!validate_line(line, line_len, data))
		return (NULL);
	matrix = alloc_matrix(data);
	if (!matrix)
		return (NULL);
	copy_line_to_matrix(matrix, line, 0, line_len);
	return (matrix);
}

char	**read_map(int fd, t_data *data)
{
	char	**matrix;
	char	line[BUFFER_SIZE];
	int		len;
	int		i;

	matrix = read_first_line(fd, data, line);
	if (!matrix)
		return (NULL);
	i = 0;
	while (++i < data->size_matrix_y)
	{
		if (!read_map_line(fd, line, &len) || len != data->size_matrix_x
			|| !validate_line(line, len, data))
		{
			free_matrix(matrix, data);
			return (NULL);
		}
		copy_line_to_matrix(matrix, line, i, len);
	}
	if (read_map_line(fd, line, &len))
	{
		free_matrix(matrix, data);
		return (NULL);
	}
	return (matrix);
}
