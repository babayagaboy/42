/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:49:49 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:49:51 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	ft_isprintable(char c)
{
	return (c >= 32 && c <= 126);
}

void	print_matrix(char **matrix, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size_matrix_y)
	{
		j = -1;
		while (++j < data->size_matrix_x)
			write(1, &matrix[i][j], 1);
		write(1, "\n", 1);
	}
}

void	free_matrix(char **matrix, t_data *data)
{
	int	i;

	if (!matrix)
		return ;
	i = -1;
	while (++i < data->size_matrix_y)
		free(matrix[i]);
	free(matrix);
}

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}
