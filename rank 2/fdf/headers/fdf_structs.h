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


#ifndef FDF_STRUCTS
# define FDF_STRUCTS

#include "../headers/fdf.h"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	float		px;
	float		py;
}	t_point;

typedef struct s_map
{
	int			width;
	int			height;
	t_point 	**points;
}	t_map;

typedef struct s_fdf 
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_lenght;
	int			endian;
	float		scale;
	float		angle;
	int			movex;
	int			movey;
	t_map		*map;
}	t_fdf;

#endif