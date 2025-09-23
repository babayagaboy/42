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

#include "../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	//t_stack *b;

	a = NULL;
	//b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], 32);
	stack_innit(&a, argv + 1);




	t_stack *pointer;

	pointer = a;
	int i = 0;
	int size = ft_stacksize(a);

	while (i < size)
	{
		ft_printf("%d node ==%p== : %d\n", i, pointer, pointer->value);
		pointer = pointer->next_node;
		i++;
	}

	ft_printf("---- after swap ----\n");
	
	rotate_cmd(&a);

	pointer = a;
	i = 0;
	while (i < size)
	{
		ft_printf("%d node ==%p== : %d\n", i, pointer, pointer->value);
		pointer = pointer->next_node;
		i++;
	}
}