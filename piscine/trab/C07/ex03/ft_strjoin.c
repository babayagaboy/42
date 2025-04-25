/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:13:41 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/04 13:13:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strcomp;
	int		counter;
	int		len;

	counter = 0;
	len = 0;
	while (counter < size)
	{
		len += ft_strlen(strs[counter]);
		counter++;
	}
	counter = 0;
	strcomp = malloc((len + (ft_strlen(sep) * (size - 1)) + 1) * sizeof(char));
	strcomp[0] = '\0';
	while (counter < size)
	{
		ft_strcat(strcomp, strs[counter]);
		if (counter < size - 1)
			ft_strcat(strcomp, sep);
		counter++;
	}
	if (size <= 0)
		strcomp = NULL;
	return (strcomp);
}
/*
int	main()
{
	int	size = 2;
	char	*sep = ", ";
	char	*strs[] = {"hello" , "world"};
	char	*strcomp;

	strcomp = ft_strjoin(size, strs, sep);
	if (strcomp)
	{
		printf("%s", strcomp);
		free(strcomp);
	}
	else
		printf("malloc error");
	return (0);
}
*/
