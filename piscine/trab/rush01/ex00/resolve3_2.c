/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve3_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:38:16 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 19:38:17 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**resolve3_2_coll(char **matrix, char **map)
{
	int	coll;

	coll = 0;
	while (coll < 4)
	{
		if ((map[0][coll] == '3' && map[1][coll] == '2')
		&& matrix[1][coll] == '0')
			matrix[1][coll] = map[0][coll];
		coll++;
	}
	coll = 0;
	while (coll < 4)
	{
		if ((map[1][coll] == '3' && map[0][coll] == '2')
		&& matrix[2][coll] == '0')
			matrix[2][coll] = map[1][coll];
		coll++;
	}
	return (matrix);
}

char	**resolve3_2_row(char **matrix, char **map)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if ((map[2][row] == '3' && map[3][row] == '2')
		&& matrix[row][1] == '0')
			matrix[row][1] = map[2][row];
		row++;
	}
	row = 0;
	while (row < 4)
	{
		if ((map[3][row] == '3' && map[2][row] == '2')
		&& matrix[row][2] == '0')
			matrix[row][2] = map[3][row];
		row++;
	}
	return (matrix);
}

char	**resolve3_2(char **matrix, char **map)
{
	matrix = resolve3_2_coll(matrix, map);
	matrix = resolve3_2_row(matrix, map);
	return (matrix);
}
