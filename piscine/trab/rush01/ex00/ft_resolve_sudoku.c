/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_sudoku.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:58:23 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 18:58:24 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**resolve_sudoku_coll(char **matrix, int coll_0, int row)
{
	int	temp_sudoku;
	int	i;

	i = 0;
	temp_sudoku = 10;
	while (i < 4)
	{
		temp_sudoku -= matrix[row][i] - '0';
		i++;
	}
	matrix[row][coll_0] = temp_sudoku + '0';
	return (matrix);
}

char	**resolve_sudoku_row(char **matrix, int row_0, int coll)
{
	int	temp_sudoku;
	int	i;

	i = 0;
	temp_sudoku = 10;
	while (i < 4)
	{
		temp_sudoku -= matrix[i][coll] - '0';
		i++;
	}
	matrix[row_0][coll] = temp_sudoku + '0';
	return (matrix);
}

char	**sudoku_coll(char **matrix)
{
	int	check_zero;
	int	coll_0;
	int	row;
	int	coll;

	row = 0;
	while (row < 4)
	{
		coll = 0;
		check_zero = 0;
		while (coll < 4)
		{
			if (matrix[row][coll] == '0')
			{
				check_zero++;
				coll_0 = coll;
			}
			coll++;
		}
		if (check_zero == 1)
			matrix = resolve_sudoku_coll(matrix, coll_0, row);
		row++;
	}
	return (matrix);
}

char	**sudoku_row(char **matrix)
{
	int	check_zero;
	int	row_0;
	int	coll;
	int	row;

	coll = 0;
	while (coll < 4)
	{
		row = 0;
		check_zero = 0;
		while (row < 4)
		{
			if (matrix[row][coll] == '0')
			{
				check_zero++;
				row_0 = row;
			}
			row++;
		}
		if (check_zero == 1)
			matrix = resolve_sudoku_row(matrix, row_0, coll);
		coll++;
	}
	return (matrix);
}

char	**resolve_sudoku(char **matrix)
{
	matrix = sudoku_coll(matrix);
	matrix = sudoku_row(matrix);
	return (matrix);
}
