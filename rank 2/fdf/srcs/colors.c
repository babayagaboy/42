/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:56:45 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/13 22:56:45 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	get_color(int z)
{
	if (z > 10)
		return (RED);
	if (z > 0)
		return (GREEN);
	return (BLUE);
}

int interpolate(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_gradiente(int start_c, int end_c, float percentage)
{
	int	r = interpolate((start_c >> 16) & 0xFF, (end_c >> 16) & 0xFF, percentage);
	int	g = interpolate((start_c >> 8) & 0xFF, (end_c >> 8) & 0xFF, percentage);
	int	b = interpolate(start_c & 0xFF, end_c & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}