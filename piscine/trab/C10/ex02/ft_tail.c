/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:38:20 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/12 20:38:22 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_atoi(char *strbytes)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	while ((strbytes[i] >= 9 && strbytes[i] <= 13) || strbytes[i] == 32)
		i++;
	while (strbytes[i] == '+' || strbytes[i] == '-')
		i++;
	while (strbytes[i] >= '0' && strbytes[i] <= '9')
	{
		bytes = (bytes * 10) + (strbytes[i] - '0');
		i++;
	}
	return (bytes);
}

void	ft_print_header(int i, char *file_name)
{
	if (i == 3)
		write(1, "==> ", 4);
	else
		write(1, "\n==> ", 5);
	while (*file_name)
		write(1, file_name++, 1);
	write(1, " <==\n", 5);
}

int	ft_file_size(char *file_name)
{
	char	buffer;
	int		fd;
	int		size;

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "ft_tail: ", 9);
		while (*file_name)
			write(2, file_name++, 1);
		write(2, ": No such file or directory\n", 28);
		return (-1);
	}
	else
		while (read(fd, &buffer, 1) > 0)
			size++;
	close(fd);
	return (size);
}

void	ft_display(char *file_name, int size, int bytes)
{
	char	buffer;
	int		fd;
	int		n;

	n = 0;
	fd = open(file_name, 0);
	while (read(fd, &buffer, 1) > 0)
	{
		if (++n >= size - bytes + 1)
			write(1, &buffer, 1);
	}
	close(fd);
}
