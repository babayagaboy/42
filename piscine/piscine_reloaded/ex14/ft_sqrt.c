/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:45:08 by hgutterr          #+#    #+#             */
/*   Updated: 2025/04/03 16:45:10 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	root;

	root = 1;
	while (root * root < nb)
		root++;
	if (root * root == nb)
		return (root);
	else
		return (0);
}
/*
int	main()
{
	printf("%d\n", ft_sqrt(100));
	printf("%d\n", ft_sqrt(64));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(300));
}*/
