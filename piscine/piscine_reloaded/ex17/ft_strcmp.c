/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:57:26 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/03 16:57:27 by hgutterr         ###   ########.fr       */
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
	char	s1[] = "h";
	char	s2[] = "";

	if (ft_strcmp(s1, s2) == 0)
		printf("the strings are equal");
	else if (ft_strcmp(s1, s2) > 0)
		printf("the string 1 is greater than string 2");
	else
		printf("the string 2 is greater than string 1");
	return (0);
}
*/
