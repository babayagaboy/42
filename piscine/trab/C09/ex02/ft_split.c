/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:05:54 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/09 01:05:55 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_wordcount(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], sep))
		{
			words++;
			while (str[i] != '\0' && !is_separator(str[i], sep))
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*ft_splitter(char *str, char *sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != '\0' && (!is_separator(str[i], sep)))
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && !is_separator(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_splitted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_splitted = malloc((ft_wordcount(str, charset) + 1) * sizeof(char *));
	if (str_splitted == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			str_splitted[j] = ft_splitter(&str[i], charset);
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
			j++;
		}
		else
			i++;
	}
	str_splitted[j] = 0;
	return (str_splitted);
}
/*
int	main(void)
{
	char	*str = "helloxworld";
	char	*charset = "x";
	char	**str_splited;

	str_splited = (ft_split(str, charset));
	for (int i = 0; str_splited[i] != NULL; i++)
		printf("%s\n", str_splited[i]);
	for (int i = 0; str_splited[i] != NULL; i++)
		free(str_splited[i]);
	free(str_splited);
	return (0);
}*/
