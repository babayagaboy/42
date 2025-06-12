/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:40:43 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/10 23:40:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../headers/fdf_macros.h"

static	int	count_words(char *line)
{
	int	count;
	count = 0;

	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
		{
			count++;
			while (*line && *line != ' ')
				line++;
		}
	}
	return (count);
}


static	t_point	*parse_line(char *line, int y)
{
	t_point	*row;
	char	**split;
	int		width;
	int		x;

	split = ft_split(line, ' ');
	width = 0;
	x = 0;
	while (split[width])
		width++;
	row = malloc(sizeof(t_point) * width);
	while (x < width)
	{
		row[x].x = x;
		row[x].y = y;
		row[x].z = ft_atoi(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
	return (row);
}


t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;

	map = malloc(sizeof(t_map));
	map->points = malloc(sizeof(t_point *) * MAX_HEIGHT);
	if (!map->points)
		return (NULL);
	map->height = 0;
	line = get_next_line(fd);

	while (line)
	{
		if (map->height == 0)
			map->width = count_words(line);
		map->points[map->height] = parse_line(line, map->height);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

