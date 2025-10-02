/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:52:36 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/11 22:52:36 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	pixel = fdf->addr + (y * fdf->line_lenght + x * (fdf->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_line_setup(t_fdf *fdf, t_point *pA, t_point *pB)
{
	t_line	*line;
	line = malloc(sizeof(t_line));
	int		i;

	line->color = WHITE;
	line->xA = (int)pA->px;
	line->yA = (int)pA->py;
	line->xB = (int)pB->px;
	line->yB = (int)pB->py;
	line->dx = abs(line->xB - line->xA);
	line->dy = abs(line->yB - line->yA);

	if (line->xA < line->xB)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->yA < line->yB)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	if (line->dx > line->dy)
		line->steps = line->dx;
	else
		line->steps = line->dy;
	while (draw_line(fdf, line, i) == 0)
		i++;
	free(line);
}

int		draw_line(t_fdf *fdf, t_line *line, int i)
{
	if (line->steps == 0)
		line->percentage = 0.0;
	else
		line->percentage = (float)i / line->steps;
	put_pixel(fdf, line->xA, line->yA, line->color);
	if (line->xA == line->xB && line->yA == line->yB)
		return (1);
	line->e2 = 2 * line->err;
	if (line->e2 > -line->dy)
	{
		line->err -= line->dy;
		line->xA += line->sx;
	}
	if (line->e2 < line->dx)
	{
		line->err += line->dx;
		line->yA += line->sy;
	}
	return (0);
}
