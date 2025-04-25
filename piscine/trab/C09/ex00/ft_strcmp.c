/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:36:32 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/27 15:36:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	s1[] = "";
	char	s2[] = "h";

	if (ft_strcmp(s1, s2) == 0)
		printf("the strings are equal");
	else if (ft_strcmp(s1, s2) >= 0)
		printf("the string 1 is greater than string 2");
	else
		printf("the string 2 is greater than string 1");
	return (0);
}
*/
