/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:39:42 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 16:25:32 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 4

char	**make_matrix(int row, int colls);

char	**make_map(char *mapstr, int row, int colls);

int		check_map(char *map);

void	resolve_matrix(char **matrix, char **map);

int	main(int argc, char **argv)
{
	char	**matrix;
	char	**map;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	else if (check_map(argv[1]) == 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	matrix = make_matrix(SIZE, SIZE);
	map = make_map(argv[1], SIZE, SIZE);
	resolve_matrix(matrix, map);
	while (i < 4)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
