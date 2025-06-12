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

#include "../headers/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	pixel = fdf->addr + (y * fdf->line_lenght + x * (fdf->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_line(t_fdf *fdf, t_point *pA, t_point *pB)
{
	int	xA;
	int	yA;
	int	xB;
	int	yB;
	int	dx; // diference in xA and xB 
	int	dy; // diference in yA and yB
	int	sx; // direction x
	int	sy; // direction y
	int	err;
	int e2;

	xA = (int)pA->px;
	yA = (int)pA->py;
	xB = (int)pB->px;
	yB = (int)pB->py;

	dx = abs(xB - xA);
	dy = abs(yB - yA);

	if (xA < xB)
		sx = 1;
	else
		sx = -1;
	if (yA < yB)
		sy = 1;
	else
		sy = -1;
	
	err = dx - dy;
	while (1)
	{
		put_pixel(fdf, xA, yA, WHITE);
		if (xA == xB && yA == yB)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			xA += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			yA += sy;
		}
	}
}
