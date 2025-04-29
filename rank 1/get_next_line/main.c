/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:39:49 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/29 17:56:31 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char	*s1;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	while (s1)
	{
		s1 = get_next_line(fd);
		if (!s1)
			break ;
		printf("%s", s1);
		free(s1);
	}
}
