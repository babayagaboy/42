/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:45:44 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/29 17:53:28 by hgutterr         ###   ########.fr       */
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
	int	len;

	pos = ft_strchr(buff, '\n');
	if (!pos)
		return (NULL);
	len = (pos - buff) + 1;
	pre = ft_substr(buff, 0, len);
	*remainer = ft_strdup(pos + 1);
	return(pre);
}

char *get_next_line(int fd)
{
	static char	*remainder;
	char	buff[BUFFER_SIZE];
	char	*s1;
	char	*partial;

	s1 = ft_strdup("");
	if (remainder)
	{
		s1 = ft_strjoin(s1, remainder);
		remainder = NULL;
	}
	while (read(fd, buff, BUFFER_SIZE))
	{
		if(ft_strchr(buff, '\n'))
		{
			partial = split_newline(buff, &remainder);
			s1 = ft_strjoin(s1, partial);
			free(partial);
			break ;
		}
		else
			s1 = ft_strjoin(s1, buff);
	}
	if (!*s1)
		return (NULL);
	return (s1);
}