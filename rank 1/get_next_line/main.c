/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:49 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/25 18:40:04 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
	}
}