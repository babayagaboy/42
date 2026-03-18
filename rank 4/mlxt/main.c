/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:03 by hgutterr          #+#    #+#             */
/*   Updated: 2026/03/18 18:37:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
		return ;
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_column(t_mlx *mlx,int x, int start, int end, int color)
{
	while (start < end)
	{
		put_pixel(mlx, x, start, color);
		start++;
	}
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

	p->plane_y = p->dir_x * 0.66; //the 2d raycaster version of camera plane
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
	if (r->ray_dir_x < 0)	// ray on the left or rigth
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)	// ray on the up or down
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

void	run_dda(t_ray *r)
{
	r->hit = 0;
	while(r->hit == 0)	// search dda till it hits a wall
	{
		if(r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->side == 0)
			r->perp_wall_dist = (r->side_dist_x - r->delta_dist_x); // fix fish eye effect
		else
			r->perp_wall_dist = (r->side_dist_y - r->delta_dist_y);
		if (worldMap[r->map_x][r->map_y] > 0)
			r->hit = 1;
	}
}

void	draw_column(t_mlx *mlx, t_ray *r, int i)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(screenHeight / r->perp_wall_dist);
	draw_start = (-1 * line_height) / 2 + screenHeight / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + screenHeight / 2;
	if (draw_start >= screenHeight)
		draw_end = screenHeight - 1;
	if (r->side == 1)
		put_column(mlx, i, draw_start, draw_end, (0x00FF0000 / 2));
	else
		put_column(mlx, i, draw_start, draw_end, 0x00FF0000);
}
	
void    calc_rays(t_mlx *mlx, t_ray *ray, t_player *player)
{
	int i;

	i = 0;
	while (i < screenWidth) // calculate ray
	{
		calc_camera(ray, player, i);
		calc_dda(ray, player);
		run_dda(ray);
		draw_column(mlx, ray, i);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		i++;
	}
}

double	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec / 1000000.0);
}

void	get_time(t_player *p)
{
	p->old_time = p->time;
	p->time = get_timestamp();
	p->frame_time = (p->time - p->old_time) / 1000.0;	// time this frame has taken, in seconds
	p->move_speed = p->frame_time * 5.0;				// const value in squares per sec
	p->rotation_speed = p->frame_time * 3.0;			// const value in radians per sec
}
int		handle_input(int key, t_player *p)
{
	if (key == KEY_UP)
	{
		printf("time = %f\n", p->time);
		if(!(ft_isdigit(worldMap[(int)(p->pos_x + (p->dir_x * p->move_speed))][(int)(p->pos_y)])))
			p->pos_x += p->dir_x * p->move_speed;
		if((worldMap[(int)(p->pos_x)][(int)(p->pos_y + (p->dir_y * p->move_speed))]))
			p->pos_y += p->dir_y * p->move_speed;
	}
	if (key == KEY_DOWN)
	{
		if(!(worldMap[(int)(p->pos_x - p->dir_x * p->move_speed)][(int)(p->pos_y)]))
			p->pos_x -= p->dir_x * p->move_speed;
		if(!(worldMap[(int)(p->pos_x)][(int)(p->pos_y - p->dir_y * p->move_speed)]))
			p->pos_y -= p->dir_y * p->move_speed;
	}
	return (0);
}

void	start(t_mlx *mlx, t_ray *ray, t_player *player)
{
	get_time(player);
	mlx_key_hook(mlx->win, handle_input, player);
	calc_rays(mlx, ray, player);
	mlx_loop(mlx->mlx);
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
	start(mlx, ray, player);
	free(mlx);
	free(player);
	free(ray);
	return (0);
}




// for(int y = 0; y < 100; y++)
// {
//     for (int x = 0; x < 100; x++) {
//         put_pixel(mlx, y, x, 0x00FF00);
//     }
// }