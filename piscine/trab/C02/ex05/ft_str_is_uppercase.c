/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:33:09 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/26 01:33:12 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	char	*str1 = "helloworld";
	char	*str2 = "HELLOWORLD";
	char	*str3 = "";

	if (ft_str_is_uppercase(str1) == 0)
		printf("its not in uppercase\n");
	else
		printf("it is in uppercase\n");
	if (ft_str_is_uppercase(str2) == 0)
		printf("its not in uppercase\n");
	else
		printf("it is in uppercase\n");
	if (ft_str_is_uppercase(str3) == 0)
		printf("its not in uppercase\n");
	else
		printf("it is in uppercase\n");
	return (0);
}
*/
