/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:15:58 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/01 18:48:33 by hgutterr         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		buff[BUFFER_SIZE];
	char		*s1;
	char		*partial;

	s1 = ft_strdup("");
	if (remainder[fd])
	{
		s1 = ft_strjoin(s1, remainder[fd]);
		remainder[fd] = NULL;
	}
	while (read(fd, buff, BUFFER_SIZE))
	{
		if (ft_strchr(buff, '\n'))
		{
			partial = split_newline(buff, &remainder[fd]);
			s1 = ft_strjoin(s1, partial);
			free(partial);
			break ;
		}
		s1 = ft_strjoin(s1, buff);
	}
	if (!*s1)
		return (free(s1), NULL);
	return (s1);
}
/* 
int	main(int argc, char **argv)
{
	int fd1;
	int fd2;
	int fd3;
	char	*s1;

	(void) argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);

	while (s1)
	{
		s1 = get_next_line(fd1);
		if (!s1)
			break ;
		printf("%s", s1);
		s1 = get_next_line(fd2);
		if (!s1)
			break ;
		printf("%s", s1);
		s1 = get_next_line(fd3);
		if (!s1)
			break ;
		printf("%s", s1);
		free(s1);
	}
} */