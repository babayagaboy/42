/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:03 by hgutterr          #+#    #+#             */
/*   Updated: 2026/03/17 18:26:29 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
		return ;
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, screenWidth, screenHeight, "cub3d");
	mlx->img = mlx_new_image(mlx->mlx, screenWidth, screenHeight);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->line_len, &mlx->endian);
}

void    init_player(t_player *p)
{
	p->pos_y = 12;  //x and y start position //get_player_coords()
	p->pos_x = 22;

	p->dir_y = 0; //initial direction vector (N, S, W, E)
	p->dir_x = -1;

	p->pos_y = p->dir_x * 0.66; //the 2d raycaster version of camera plane
	p->plane_x = -p->dir_y * 0.66;
	
	p->time = 0; //time of current frame
	p->old_time = 0; //time of previous frame
}

void    calc_camera(t_ray *r, t_player *p, int i)
{
	r->camera_x = 2 * i / (double)screenWidth - 1;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camera_x;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camera_x;
}

void	calc_dda(t_ray *r, t_player *p)
{
	r->map_x = (int)p->pos_x; //our position in the map
	r->map_y = (int)p->pos_y;

	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);	// same thing has pythagoras theorem
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;						//edge case if delta_dist = 0
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
	if (r->ray_dir_x < 0) // ray on the left
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_dist_y;
	}
}

void    calc_rays(t_ray *ray, t_player *player)
{
	int i;

	i = 0;
	while (i < screenWidth) // calculate ray
	{
		calc_camera(ray, player, i);
		calc_dda(ray, player);
		run_dda(); //TODO
		draw_column(); //TODO
		i++;
	}
}

int	main(void)
{
	t_mlx		*mlx;
	t_player	*player;
	t_ray		*ray;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	init_mlx(mlx);
	if (!mlx->mlx || !mlx->win || !mlx->img || !mlx->addr)
		return (free(mlx), 1);
	
	player = malloc(sizeof(t_player));
	if (!player)
		return (free(mlx), 1);
	init_player(player);
	
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (free(mlx), free(player), 1);
	calc_rays(ray, player);

	mlx_loop(mlx->mlx);
	free(mlx);
	free(player);
	free(ray);
	return (0);
}




// for(int y = 0; y < 100; y++)
// {
//     for (int x = 0; x < 100; x++) {
//         put_pixel(mlx, y, x, 0x00FF00);
//         mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
//     }
// }