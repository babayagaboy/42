/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:06:04 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/15 19:06:04 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

long	ft_atol_1(char **strptr)
{
	int					sign;
	long				i;
	long				result;
	char				*nptr;

	i = 0;
	nptr = *strptr;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	*strptr = nptr + i;
	return ((long) sign * result);
}

void	parse(t_stack **a, t_stack **b, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == ' ')
			j++;
		if (argv[i][j] != '\0')
		{
			stack_innit(a, ft_atol_1(&argv[i]));
			if (*argv[i] == '\0')
				i++;
			else if (*argv[i] != ' ')
				free_exit(a);
		}
		else
			i++;
	}
	sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (ft_printf("Error"), 1);
	else
		parse(&a, &b, argv);
	free_stack(&a);
	return (0);
}
