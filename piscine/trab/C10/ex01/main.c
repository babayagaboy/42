/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:15:48 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/12 01:15:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

#define SIZE_BUFFER 30000

void	ft_cat(int ac, char **av);

int	main(int argc, char **argv)
{
	ft_cat(argc, argv);
	return (0);
}
