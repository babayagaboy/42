/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:04:11 by hgutterr          #+#    #+#             */
/*   Updated: 2025/10/02 13:29:02 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../inc/fdf_macros.h"
# include "../inc/fdf_structs.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

// draw.c

void			put_pixel(t_fdf *fdf, int x, int y, int color);
void			draw_line_setup(t_fdf *fdf, t_point *pA, t_point *pB);
int				draw_line(t_fdf *fdf, t_line *line, int i);

// read_map.c

static	int		count_words(char *line);
static	t_point	*parse_line(char *line, int y);
t_map			*read_map(int fd);

// render.c

void			render_map(t_map *map, t_fdf *fdf);

// project.c

t_point			*project_point(t_point *p, t_fdf *fdf);

// fdf.c

int				key_hook(int keycode, void *param);
void			re_mlx(t_fdf *fdf);
void			put_instructions(t_fdf *fdf);
void			ft_free(t_map **map, t_fdf *fdf);
void			init_fdf(t_fdf *fdf, t_map *map);

// colors.c

int				get_color(int z);
int				interpolate(int start, int end, float percentage);
int				get_gradiente(int start_c, int end_c, float percentage);

#endif