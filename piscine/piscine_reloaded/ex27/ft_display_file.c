/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:25:18 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/07 16:25:20 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_display_file(char *filename)
{
	char	buffer;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buffer, 1))
		write(1, &buffer, 1);
	close (fd);
	return (1);
}
