/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:15:58 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/12 14:41:53 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
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

char	*split_newline(char *buff, char *remainer)
{
	char	*pos;
	char	*pre;
	int		len;
	int		i;

	i = 0;
	pos = ft_strchr(buff, '\n');
	if (!pos)
		return (NULL);
	len = (pos - buff) + 1;
	pre = ft_substr(buff, 0, len);
	while (pos[i])
	{
		remainer[i] = pos[i + 1];
		i++;
	}
	remainer[i] = '\0';
	return (pre);
}

char	*join_lines(char *buff, char *remainder, char *s1)
{
	char	*temp;

	temp = split_newline(buff, remainder);
	s1 = ft_strjoin(s1, temp);
	return (free(temp), s1);
}

char	*get_line(char *s1, int fd, char *buff, int bytes)
{
	static char	remainder[1024][BUFFER_SIZE];
	int			i;

	if (ft_strchr(remainder[fd], '\n'))
		return (join_lines(remainder[fd], remainder[fd], s1));
	s1 = ft_strjoin(s1, remainder[fd]);
	i = 0;
	while (remainder[fd][i])
		remainder[fd][i++] = '\0';
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		if (ft_strchr(buff, '\n'))
			return (join_lines(buff, remainder[fd], s1));
		s1 = ft_strjoin(s1, buff);
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
	s1 = ft_strdup("");
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

/* int main()
{
	int fd = open("a", O_RDONLY);
	int fdb = open("b", O_RDONLY);
	char *a;
	int i = 0;

	while ((a = get_next_line(fd)))
	{
		printf("%d:%s", ++i, a);
		free (a);
	}
	i = 0;
	while ((a = get_next_line(fdb)))
	{
		printf("%d:%s", ++i, a);
		free (a);
	}

	return 0; 
} */