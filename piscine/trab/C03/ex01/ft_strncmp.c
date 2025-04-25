/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:36 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/27 16:20:40 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
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
	char	s1[] = "hello, world!";
	char	s2[] = "hello";
	unsigned int n = 5;

	if (ft_strncmp(s1, s2, n) == 0)
		printf("the strings are equal");
	else if (ft_strncmp(s1, s2, n) >= 0)
		printf("the string 1 is greater than string 2");
	else
		printf("the string 2 is greater than string 1");
	return (0);
}
*/
