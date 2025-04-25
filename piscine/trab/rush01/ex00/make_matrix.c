/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:33:59 by myivanov          #+#    #+#             */
/*   Updated: 2025/02/02 16:40:55 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**make_matrix(int rows, int cols)
{
	char	**matrix;
	int		i;

	rows = 4;
	cols = 4;
	i = 0;
	matrix = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
		matrix[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	return (matrix);
}
