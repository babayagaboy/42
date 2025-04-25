/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:21:16 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 20:00:57 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	**resolve4(char **matrix, char **map);
char	**resolve_sudoku_coll(char **matrix, char **map, int coll_0, int row);
char	**resolve_sudoku_row(char **matrix, char **map, int row_0, int coll);
char	**resolve_sudoku(char **matrix);
char	**resolve1(char **matrix, char **map);
char	**resolvebruteforce(char **matrix);

void	ft_print_matrix(char **matrix, int row, int coll)
{
	int	i;
	int	j;
	int	space_counter;

	i = 0;
	while (i < row)
	{
		j = 0;
		space_counter = 0;
		while (j < coll)
		{
			write(1, &matrix[i][j], 1);
			if (space_counter < 3)
			{
				write(1, " ", 1);
				space_counter++;
			}
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	resolve_matrix(char **matrix, char **map)
{
	int	row;
	int	coll;

	row = 0;
	while (row < 4)
	{
		coll = 0;
		while (coll < 4)
			matrix[row][coll++] = '0';
		row++;
	}
	matrix = resolve4(matrix, map);
	matrix = resolve1(matrix, map);
	matrix = resolve_sudoku(matrix);
	matrix = resolve_sudoku(matrix);
	matrix = resolve_sudoku(matrix);
	matrix = resolve_sudoku(matrix);
	matrix = resolvebruteforce(matrix);
	ft_print_matrix(matrix, row, coll);
}
