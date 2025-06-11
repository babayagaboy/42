/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:04:11 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/11 18:09:11 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_point {
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	t_point **points;
	int		width;
	int		height;
}	t_map;

static	int	count_words(char *line);
static	t_point	*parse_line(char *line, int y);
t_map	*read_map(int fd);

#endif