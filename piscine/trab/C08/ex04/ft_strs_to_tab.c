/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:26:34 by hgutterr          #+#    #+#             */
/*   Updated: 2025/02/06 13:26:36 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
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

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					index;

	index = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	while (index < ac)
	{
		if (av[index] == NULL)
			return (NULL);
		arr[index].size = ft_strlen(av[index]);
		arr[index].str = ft_strdup(av[index]);
		arr[index].copy = ft_strdup(av[index]);
		if (arr[index].str == NULL || arr[index].copy == NULL)
			return (NULL);
		index++;
	}
	arr[index].str = NULL;
	return (arr);
}
/*
void	print_array(t_stock_str *str)
{
	int	i;

	i = 0;

	while (str[i].str != NULL)
	{
		printf("Index: %d - Size: %d - String: %s - Copy: %s\n",
		i, str[i].size,	str[i].str, str[i].copy);
	       i++;	
	}
	free(str);
}

int	main(int argc, char **argv)
{
	print_array(ft_strs_to_tab(argc, argv));
}
*/
