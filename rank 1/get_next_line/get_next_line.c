/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:45:44 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/24 16:45:46 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char buff;
	int start;
	size_t bytes;

	if (!start)
		start = 0;
	bytes = 0;
	while (buff != '\0' && buff != '\n')
	{
		bytes += read(fd, &buff, 1);
		if (bytes > start)
			write(1, &buff, 1);	
	}
	start = bytes;
	printf("%d\n", bytes);
	close(fd);
	return (NULL);
}