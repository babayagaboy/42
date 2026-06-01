/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:21:29 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 09:21:29 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float area(Point const a, Point const b, Point const c)
{
	float area;

	area =	(
			(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
			+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
			) / 2;
	return((area >= 0) ? area : -area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float t0, t1, t2, t3;

	t0 = area(a, b, c);
	t1 = area(point, a, b);
	t2 = area(point, a, c);
	t3 = area(point, b, c);

	if (t1 == 0 || t2 == 0 || t3 == 0)
		return(false);
	else if (t1 + t2 + t3 == t0)
		return(true);
	return(false);
}