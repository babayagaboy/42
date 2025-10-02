/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:08:07 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/11 23:08:07 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	render_map(t_map *map, t_fdf *fdf)
{
	t_point		*p1;
	t_point		*p2;
	int			x;
	int			y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x + 1 < map->width)
			{
				p1 = project_point(&map->points[y][x], fdf);
				p2 = project_point(&map->points[y][x + 1], fdf);
				draw_line_setup(fdf, p1, p2);
			}
			if (y + 1 < map->height)
			{
				p1 = project_point(&map->points[y][x], fdf);
				p2 = project_point(&map->points[y + 1][x], fdf);
				draw_line_setup(fdf, p1, p2);
			}
		}
	}
}
