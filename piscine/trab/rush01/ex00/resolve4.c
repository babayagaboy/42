/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:30:59 by myivanov          #+#    #+#             */
/*   Updated: 2025/02/02 18:35:08 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_4collup(char **matrix, char **map)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (map[0][j] == '4')
		{
			i = 1;
			num = 1;
			matrix[0][j] = '1';
			while (i <= 3)
			{
				matrix[i][j] = num + 1 + '0';
				i++;
				num++;
			}
		}
		j++;
	}
	return (matrix);
}

char	**ft_4colldown(char **matrix, char **map)
{
	int	num;
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		if (map[1][j] == '4')
		{
			i = 2;
			num = 1;
			matrix[3][j] = '1';
			while (i >= 0)
			{
				matrix[i][j] = num + 1 + '0';
				i--;
				num++;
			}
		}
		j++;
	}
	return (matrix);
}

char	**ft_4rowleft(char **matrix, char **map)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (map[2][i] == '4')
		{
			num = 1;
			j = 1;
			matrix[i][0] = '1';
			while (j <= 3)
			{
				matrix[i][j] = num + 1 + '0';
				num++;
				j++;
			}
		}
		i++;
	}
	return (matrix);
}

char	**ft_4rowright(char **matrix, char **map)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (map[3][i] == '4')
		{
			j = 2;
			num = 1;
			matrix[i][3] = '1';
			while (j >= 0)
			{
				matrix[i][j] = num + 1 + '0';
				j--;
				num++;
			}
		}
		i++;
	}
	return (matrix);
}

char	**resolve4(char **matrix, char **map)
{
	matrix = ft_4collup(matrix, map);
	matrix = ft_4colldown(matrix, map);
	matrix = ft_4rowleft(matrix, map);
	matrix = ft_4rowright(matrix, map);
	return (matrix);
}
