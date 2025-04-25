/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:51:55 by arpereir          #+#    #+#             */
/*   Updated: 2025/02/12 21:51:56 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/bsq.h"

int	validate_chars(t_data *data)
{
	if (!ft_isprintable(data->empty) || !ft_isprintable(data->obst)
		|| !ft_isprintable(data->full))
		return (0);
	if (data->empty == data->obst || data->empty == data->full
		|| data->obst == data->full)
		return (0);
	return (1);
}

int	parse_number(char *str, int len)
{
	int	num;
	int	i;

	num = 0;
	i = -1;
	while (++i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		num = num * 10 + (str[i] - '0');
	}
	return (num);
}

int	extract_header_info(char *buffer, int len, t_data *data)
{
	int	i;
	int	num_len;

	i = len - 1;
	data->full = buffer[i--];
	data->obst = buffer[i--];
	data->empty = buffer[i--];
	num_len = i + 1;
	if (!validate_chars(data))
		return (0);
	data->size_matrix_y = parse_number(buffer, num_len);
	return (data->size_matrix_y > 0);
}

int	read_header(int fd, t_data *data)
{
	char	buffer[15];
	int		i;

	i = 0;
	while (i < 14 && read(fd, &buffer[i], 1) > 0 && buffer[i] != '\n')
		i++;
	if (i < 4 || buffer[i] != '\n')
		return (0);
	return (extract_header_info(buffer, i, data));
}

int	validate_line(char *line, int len, t_data *data)
{
	int	i;

	i = -1;
	while (++i < len)
		if (line[i] != data->empty && line[i] != data->obst)
			return (0);
	return (1);
}
