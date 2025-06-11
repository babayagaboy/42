/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:45:44 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/11 01:02:05 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_gnl_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*split_newline(char *buff, char *remainder)
{
	char	*pos;
	char	*pre;
	int		len;
	int		i;

	i = 0;
	pos = ft_gnl_strchr(buff, '\n');
	if (!pos)
		return (NULL);
	len = (pos - buff) + 1;
	pre = ft_gnl_substr(buff, 0, len);
	while (pos[i])
	{
		remainder[i] = pos[i + 1];
		i++;
	}
	remainder[i] = '\0';
	return (pre);
}

char	*join_lines(char *buff, char *remainder, char *s1)
{
	char	*temp;

	temp = split_newline(buff, remainder);
	s1 = ft_gnl_strjoin(s1, temp);
	return (free(temp), s1);
}

char	*get_line(char *s1, int fd, char *buff, int bytes)
{
	static char	remainder[BUFFER_SIZE];
	int			i;

	if (ft_gnl_strchr(remainder, '\n'))
		return (join_lines(remainder, remainder, s1));
	s1 = ft_gnl_strjoin(s1, remainder);
	i = 0;
	while (remainder[i])
		remainder[i++] = '\0';
	while (bytes > 0)
	{
		i = 0;
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		if (ft_gnl_strchr(buff, '\n'))
			return (join_lines(buff, remainder, s1));
		s1 = ft_gnl_strjoin(s1, buff);
		while (buff[i])
			buff[i++] = 0;
	}
	if (!*s1)
		return (free(s1), NULL);
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*s1;
	int			bytes;
	char		*buff;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s1 = ft_gnl_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!s1 || !buff)
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		buff[i++] = '\0';
	bytes = 1;
	s1 = get_line(s1, fd, buff, bytes);
	if (buff)
		free(buff);
	return (s1);
}

/* int	main(int argc, char **argv)
{
	int	fd;
	int i = 0;
	char	*s1 = "";

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	while (s1 && argv[1])
	{
		s1 = get_next_line(fd);
		if (!s1)
			break ;
		printf("%d:%s", ++i, s1);
		free(s1);
	}
	close(fd);
} */