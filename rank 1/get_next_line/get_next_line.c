/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:45:44 by hgutterr          #+#    #+#             */
/*   Updated: 2025/05/06 17:40:21 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*remainder;
	char		buff[BUFFER_SIZE + 1];

	if (remainder)
	{
		s1 = ft_strjoin(s1, remainder);
		free(remainder);
		remainder = NULL;
	}
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		if (ft_strchr(buff, '\n'))
			return (ft_strjoin(s1, split_newline(buff, &remainder)));
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
	int	fd;
	char	*s1;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	while (s1 && argv[1])
	{
		s1 = get_next_line(fd);
		if (!s1)
			break ;
		printf("%s", s1);
		free(s1);
	}
} */