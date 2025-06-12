/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:45:12 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/03 22:45:12 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include <stdlib.h>


int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == ESC_KEY)
		mlx_loop_end(fdf->mlx);
	return (0);
}

void	ft_free(t_map **map, t_fdf *fdf)
{
	int	i;

	if (map && *map)
	{
		i = 0;
		while (i < (*map)->height)
			free((*map)->points[i++]);
		free((*map)->points);
		free(*map);
	}

	if (fdf && fdf->mlx)
	{
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
}


void	init_fdf(t_fdf *fdf, t_map *map)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FDF - hgutterr");
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_lenght, &fdf->endian);
	fdf->map = map;
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	fdf;
	int		fd;
	
	if (argc != 2)
	return (ft_putendl_fd("Usage: ./fdf <map.fdf>", 2), 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) ||
	ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4) != 0)
		return (ft_putendl_fd("Error: File must have .fdf extension", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	
	map = read_map(fd);
	init_fdf(&fdf, map);
	render_map(map, &fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	ft_free(&map, &fdf);
	return (0);
}





/* 
	void	*mlx;
	void	*win;
	int		winx = 800;
	int		winy = 600;
	void	*img;
	char	*addr;
	int		bpp, line_length, endian;
	int sizex = 200;
	int sizey = 200;
	int y, x;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "FDF");
	img = mlx_new_image(mlx, 800, 600);
	addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);

	int x0 = winx / 2 - sizex / 2;
	int y0 = winy / 2 - sizey / 2;

	for (y = 0; y < sizey; y++)
	{
		for (x = 0; x < sizex; x++)
		{
			int px = x0 + x;
			int py = y0 + y;
			*(int *)(addr + (py * line_length + px * (bpp / 8))) = RED;
		}
	}
	
	int line_y = y0;
	for (int i = 0; i <= sizey; i += 20)
	{
		for (int x = 0; x < sizex; x++)
		{
			int px = x0 + x;
			int py = y0 + i;
			*(int *)(addr + (py * line_length + px * (bpp / 8))) = GREEN;
		}
	}

	int	line_x = x0;
	for (int i = 0; i <= sizex; i += 20)
	{
		for (int y = 0; y < sizey; y++)
		{
			int px = x0 + i; 
			int py = y0 + y;
			*(int *)(addr + (py * line_length + px * (bpp / 8))) = BLUE;
		}
	}
	
	int		x;
	int		y;
	printf("map w: %d\n", map->width);
	printf("map h: %d\n", map->height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("%d ", map->points[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}



	mlx_put_image_to_window(mlx, win, img, 0, 0);
	
	mlx_key_hook(win, key_hook, NULL);
	mlx_loop(mlx); */