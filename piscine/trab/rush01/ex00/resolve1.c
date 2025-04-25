/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:32:54 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 19:32:56 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**resolve1_coll(char **matrix, char **map)
{
	int	coll;

	coll = 0;
	while (coll < 4)
	{
		if (map[0][coll] == '1')
			matrix[0][coll] = '4';
		coll++;
	}
	coll = 0;
	while (coll < 4)
	{
		if (map[1][coll] == '1')
			matrix[3][coll] = '4';
		coll++;
	}
	return (matrix);
}

char	**resolve1_row(char **matrix, char **map)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (map [2][row] == '1')
			matrix[row][0] = '4';
		row++;
	}
	row = 0;
	while (row < 4)
	{
		if (map [3][row] == '1')
			matrix[row][3] = '4';
		row++;
	}
	return (matrix);
}

char	**resolve1(char **matrix, char **map)
{
	matrix = resolve1_coll(matrix, map);
	matrix = resolve1_row(matrix, map);
	return (matrix);
}
