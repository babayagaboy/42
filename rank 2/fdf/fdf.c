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

#include "fdf.h"
#include <stdlib.h>
#define ESC_KEY 65307
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define WHITE 0x00FFFFFF


int	key_hook(int keycode, void *param)
{
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
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
			*(int *)(addr + (py * line_length + px * (bpp / 8))) = GREEN;
		}
	}
	

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	
	mlx_key_hook(win, key_hook, NULL);
	mlx_loop(mlx);
}
