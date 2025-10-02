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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	(void) b;
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		stack_innit(&a, argv);
	}
	else
		stack_innit(&a, argv + 1);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}
