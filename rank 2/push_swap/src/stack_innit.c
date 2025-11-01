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

int	ft_check_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_char(char *c)
{
	int	i;

	i = 0;
	if (c[i] && (c[i] == '+' || c[i] == '-'))
		i++;
	if (!(c[i]) || (c[i] == '+' || c[i] == '-'))
		return (1);
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_connect_node(t_stack **a, int nbr)
{
	t_stack		*node;
	t_stack		*last_node;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->value = nbr;
	node->next = NULL;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lastnode(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_innit(t_stack **a, long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		free_exit(a);
	else if (ft_check_repetition(*a, (int)nbr))
		free_exit(a);
	ft_connect_node(a, (int)nbr);
}
