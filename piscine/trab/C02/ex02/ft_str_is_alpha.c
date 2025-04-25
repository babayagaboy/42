/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:05:02 by hgutterr          #+#    #+#             */
/*   Updated: 2025/01/26 17:05:03 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 65 && str[i] <= 90)
				|| (str[i] >= 97 && str[i] <= 122)))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	char	*str1 = "helloworld";
	char	*str2 = "";
	char	*str3 = "HELLOWORLD";

	if (ft_str_is_alpha(str1) == 0)
		printf("does not contain only letters\n");
	else
		printf("does contain only letters\n");
	if (ft_str_is_alpha(str2) == 0)
		printf("does not contain only letters\n");
	else
		printf("does contain only letters\n");
	if (ft_str_is_alpha(str3) == 0)
		printf("does not contain only letters\n");
	else
		printf("does contain only letters\n");
	return (0);
}
*/
