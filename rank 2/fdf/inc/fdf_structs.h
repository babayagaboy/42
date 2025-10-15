/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:32:34 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/11 22:32:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H
# include "../inc/fdf.h"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	float		px;
	float		py;
	int			color;
}				t_point;

typedef struct s_line
{
	int			xA;
	int			yA;
	int			xB;
	int			yB;
	int			dx; // diference in xA and xB 
	int			dy; // diference in yA and yB
	int			sx; // direction x
	int			sy; // direction y
	int			err;
	int			e2;
	int			i;
	int			steps;
	int			color;
	float		percentage;
}				t_line;

typedef struct s_map
{
	int			width;
	int			height;
	t_point		**points;
}				t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			end;
	float		scale;
	float		angle;
	int			movex;
	int			movey;
	t_map		*map;
}				t_fdf;

#endif