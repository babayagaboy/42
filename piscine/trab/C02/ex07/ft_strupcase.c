/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:42:39 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/26 01:42:40 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
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

  	printf("strlower = %s\n", str1);
	printf("strupper = %s\n\n", ft_strupcase(str1));

	printf("strlower = %s\n", str2);
	printf("strupper = %s\n\n", ft_strupcase(str2));

	printf("strlower = %s\n", str3);
	printf("strupper = %s\n", ft_strupcase(str3));
	return (0);
}
*/
