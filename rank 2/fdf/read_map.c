/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:40:43 by hgutterr          #+#    #+#             */
/*   Updated: 2025/06/10 23:40:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	count_words(char *line) // x value
{
	int	count;
	count = 0;

	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
		{
			count++;
			while (*line && *line != ' ')
				line++;
		}
	}
	return (count);
}