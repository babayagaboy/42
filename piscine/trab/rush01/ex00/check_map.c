/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:06:41 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/02 16:32:20 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	check_map(char *map)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i] != '\0')
	{
		if ((map[i] >= '1' && map[i] <= '4') && i % 2 == 0)
			i++;
		else if (map[i] == ' ' && i % 2 != 0)
			i++;
		else
			return (0);
	}
	return (1);
}

char	**ft_fill_map(char **map, char *mapstr, int rows, int colls)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (i < rows)
	{
		j = 0;
		while (j < colls)
		{
			map[i][j] = mapstr[index];
			index += 2;
			j++;
		}
		i++;
	}
	return (map);
}

char	**make_map(char *mapstr, int rows, int colls)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **) malloc(rows * sizeof (char *));
	while (i < rows)
	{
		map[i] = (char *) malloc(colls * sizeof (char));
		i++;
	}
	map = ft_fill_map(map, mapstr, rows, colls);
	return (map);
}
