/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:35:26 by hgutterr          #+#    #+#             */
/*   Updated: 2025/10/09 13:35:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./fdf <map.fdf>", 2), 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4) != 0)
		return (ft_putendl_fd("Error: File must have .fdf extension", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	map = read_map(fd);
	init_fdf(&fdf, map);
	render_map(map, &fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	put_instructions(&fdf);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	ft_free(&map, &fdf);
	return (0);
}