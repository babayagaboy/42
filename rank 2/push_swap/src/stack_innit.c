/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_innit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:25:02 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/15 19:25:02 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_check_repetition(t_stack *a, int nbr)
{
	if(a == NULL)
		return (0);
	while(a)
	{
		if(a->value == nbr)
			return (1);
		a = a->next_node;
	}
	return(0);
}

void	ft_connect_node(t_stack **a, int nbr)
{
	t_stack *node;
	t_stack *last_node;

	if(a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->value = nbr;
	node->next_node = NULL;
	if (*a == NULL)
	{
		*a = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = ft_lastnode(*a);
		last_node->next_node = node;
		node->prev_node = last_node;
	}
}

void		stack_innit(t_stack **a, char **argv)
{
	static int		i;
	long	nbr;

	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if(nbr < INT_MIN || nbr > INT_MAX)
			exit (2);
		else if(ft_check_repetition(*a, (int)nbr))
			exit (2);
		ft_connect_node(a, (int)nbr);
		i++;
	}
}