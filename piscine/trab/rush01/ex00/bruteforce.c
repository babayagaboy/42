/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:52:48 by myivanov          #+#    #+#             */
/*   Updated: 2025/02/02 19:56:19 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_valid(char **matrix, int row, int coll, char num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (matrix[i][coll] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve_brute_force(char **matrix, int row, int coll)
{
	char	num;
	int		next_row;
	int		next_coll;

	if (row == 4)
		return (1);
	next_row = row + (coll + 1) / 4;
	next_coll = (coll + 1) % 4;
	if (matrix[row][coll] != '0')
		return (solve_brute_force(matrix, next_row, next_coll));
	num = '1';
	while (num <= '4')
	{
		if (is_valid(matrix, row, coll, num))
		{
			matrix[row][coll] = num;
			if (solve_brute_force(matrix, next_row, next_coll))
				return (1);
			matrix[row][coll] = '0';
		}
		num++;
	}
	return (0);
}

char	**resolvebruteforce(char **matrix)
{
	if (solve_brute_force(matrix, 0, 0))
	{
		return (matrix);
	}
	else
	{
		return (matrix);
	}
}
