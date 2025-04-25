/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:15:46 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/26 17:15:48 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char	str1[] = "helloworld";
	char	str2[] = "HELLOW231ORLD";
	char	str3[] = "";

  	printf("strupper = %s\n", str1);
	printf("strlower = %s\n\n", ft_strlowcase(str1));

	printf("strupper = %s\n", str2);
	printf("strlower = %s\n\n", ft_strlowcase(str2));

	printf("strupper = %s\n", str3);
	printf("strlower = %s\n", ft_strlowcase(str3));
	return (0);
}
*/
