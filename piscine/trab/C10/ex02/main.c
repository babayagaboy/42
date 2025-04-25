/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:08:54 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/13 14:08:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_display(char *file_name, int size, int bytes);

void	ft_print_header(int i, char *file_name);

int		ft_atoi(char *strbytes);

int		ft_file_size(char *file_name);

int	main(int argc, char **argv)
{
	int	i;
	int	size;
	int	bytes;

	i = 3;
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argc >= 4)
	{
		bytes = ft_atoi(argv[2]);
		while (i < argc)
		{
			if (argc > 4)
				ft_print_header(i, argv[i]);
			size = ft_file_size(argv[i]);
			ft_display(argv[i], size, bytes);
			i++;
		}
	}
	else
		write(1, "Use: ./ft_tail -c N file1 file2 ...\n", 37);
}
