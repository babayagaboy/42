/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:43:31 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/12 00:43:31 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

t_point	*project_point(t_point *p, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;

	x = p->x * SCALE;
	y = p->y * SCALE;
	z = p->z * (SCALE / 7);
	p->px = (x - y) * cos(ANGLE);
	p->py = (x + y) * sin(ANGLE) - z;

	p->px += WIN_W / 2; //- ((fdf->map->width * SCALE * cos(ANGLE)) / 7);
	//p->py += WIN_H / 2; //- ((fdf->map->height * SCALE * sin(ANGLE)) / 2);

	return (p);
}