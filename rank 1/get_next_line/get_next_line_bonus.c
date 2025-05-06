/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:15:58 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/06 17:41:38 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = ft_calloc(ft_strlen(s) + 1, 1);
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

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char ) c)
			return ((char *) s);
		s++;
	}
	if ((char ) c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*split_newline(char *buff, char **remainer)
{
	char	*pos;
	char	*pre;
	int		len;

	pos = ft_strchr(buff, '\n');
	if (!pos)
		return (NULL);
	len = (pos - buff) + 1;
	pre = ft_substr(buff, 0, len);
	*remainer = ft_strdup(pos + 1);
	return (pre);
}

char	*get_line(char *s1, int fd, int bytes)
{
	static char	*remainder[1024];
	char		buff[BUFFER_SIZE + 1];

	if (remainder[fd])
	{
		s1 = ft_strjoin(s1, remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		if (ft_strchr(buff, '\n'))
			return (ft_strjoin(s1, split_newline(buff, &remainder[fd])));
		s1 = ft_strjoin(s1, buff);
	}
	if (!*s1)
		return (free(s1), NULL);
	return (s1);
}

char	*get_next_line(int fd)
{
	char	*s1;
	int		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	bytes = 1;
	return (get_line(s1, fd, bytes));
}

/* int	main(int argc, char **argv)
{
	int		fd[argc - 1];
	char	*line;
	int		files_open = 0;
	int		i;

	if (argc < 2)
		return (printf("Usage: %s <file1> <file2> ...\n", argv[0]), 1);
	while (files_open < argc - 1)
	{
		fd[files_open] = open(argv[files_open + 1], O_RDONLY);
		if (fd[files_open] < 0)
			perror(argv[files_open + 1]);
		files_open++;
	}
	while (1)
	{
		int lines_read = 0;
		i = 0;
		while (i < argc - 1)
		{
			if (fd[i] >= 0)
			{
				line = get_next_line(fd[i]);
				if (line)
				{
					printf("fd %d: %s", i, line);
					free(line);
					lines_read++;
				}
			}
			i++;
		}
		if (lines_read == 0)
			break ;
	}
	i = 0;
	while (i < argc - 1)
		if (fd[i] >= 0)
			close(fd[i++]);
	return (0);
} */