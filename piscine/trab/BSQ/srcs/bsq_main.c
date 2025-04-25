/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:57:33 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 22:06:12 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

#define TMP_FILE "/tmp/bsq_tmp_map"
#define BUFFER_SIZE 8192

int	copy_stdin_to_file(void)
{
	int		tmp_fd;
	char	buf[BUFFER_SIZE];
	int		bytes;

	tmp_fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd == -1)
		return (-1);
	bytes = read(0, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		write(tmp_fd, buf, bytes);
		bytes = read(0, buf, BUFFER_SIZE);
	}
	close(tmp_fd);
	return (open(TMP_FILE, O_RDONLY));
}

int	process_map_fd(int fd)
{
	t_data	data;
	char	**matrix;

	if (!read_header(fd, &data))
	{
		ft_putstr("map error\n", 2);
		return (1);
	}
	matrix = read_map(fd, &data);
	if (!matrix)
	{
		ft_putstr("map error\n", 2);
		return (1);
	}
	solve(matrix, &data);
	print_matrix(matrix, &data);
	free_matrix(matrix, &data);
	return (0);
}

int	process_stdin(void)
{
	int	fd;
	int	result;

	fd = copy_stdin_to_file();
	if (fd == -1)
	{
		ft_putstr("map error\n", 2);
		return (1);
	}
	result = process_map_fd(fd);
	close(fd);
	return (result);
}

int	process_file(char *filename)
{
	int	fd;
	int	result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error\n", 2);
		return (1);
	}
	result = process_map_fd(fd);
	close(fd);
	return (result);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (process_stdin());
	i = 0;
	while (++i < argc)
	{
		process_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
	return (0);
}
