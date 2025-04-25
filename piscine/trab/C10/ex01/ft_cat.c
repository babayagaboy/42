/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:34:17 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/09 18:34:18 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define SIZE_BUFFER 30000

void	ft_display_file(int fd)
{
	char	buffer[SIZE_BUFFER];
	int		bytes;

	bytes = read(fd, buffer, SIZE_BUFFER);
	while (bytes > 0)
	{
		write(1, buffer, bytes);
		bytes = read(fd, buffer, SIZE_BUFFER);
	}
	close(fd);
}

void	ft_cat(int ac, char **av)
{
	int	i;
	int	fd;

	i = 1;
	if (ac == 1)
	{
		ft_display_file(0);
	}
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			write(2, "ft_cat: ", 8);
			while (*(av[i]))
				write(2, (av[i])++, 1);
			write(2, ": No such file or directory\n", 28);
		}
		else
			ft_display_file(fd);
		close(fd);
		i++;
	}
}
