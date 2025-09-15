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

	x = p->x * fdf->scale;
	y = p->y * fdf->scale;
	z = p->z * (fdf->scale / 7);
	p->px = (x - y) * cos(fdf->angle);
	p->py = (x + y) * sin(fdf->angle) - z;
	p->px += WIN_W / 2 + fdf->movex;
	p->py += WIN_H / 4 + fdf->movey;
	return (p);
}
