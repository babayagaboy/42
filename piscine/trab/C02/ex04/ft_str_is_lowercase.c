/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:28:13 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/26 01:28:15 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	char	*str1 = "helloworld";
	char	*str2 = "h3110, w0r1d";
	char	*str3 = "";

	if (ft_str_is_lowercase(str1) == 0)
		printf("its not in lowercase\n");
	else
		printf("it is in lowercase\n");
	if (ft_str_is_lowercase(str2) == 0)
		printf("its not in lowercase\n");
	else
		printf("it is in lowercase\n");
	if (ft_str_is_lowercase(str3) == 0)
		printf("its not in lowercase\n");
	else
		printf("it is in lowercase\n");
	return (0);
}
*/
