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

int		ft_parse(char *fdf_map)
{
	char	*temp;

	temp = ft_strrchr(fdf_map, '.');
	if(temp != NULL)
	{
		if(!ft_strncmp(temp, "fdf", 3))
			return (-1);
	}
	else
		return (-1);
}

int	main(int argc, char **argv)
{
/* 	void	*mlx;
	void	*mlx_win;
 */
	if (argc < 2)
		return(ft_putstr_fd("Not enought arguments\n", 2), -1);
	if (argc > 2)
		return(ft_putstr_fd("To many arguments\n", 2), -1);
	if (!ft_parse(argv[2]))
		return(ft_putstr_fd("Error reading the map\n", 2), -1);
	else
		ft_putstr_fd("ok\n", 2);
	
/* 	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Fdf");
	mlx_loop(mlx);
	(void) mlx_win; 
	
	
	https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc
	
	*/
	return (0);
}
