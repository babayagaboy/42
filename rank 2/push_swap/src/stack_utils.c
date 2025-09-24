/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:45:59 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/16 16:45:59 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_lastnode(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next_node)
		stack = stack->next_node;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_stack	*ptr;

	if (!stack)
		return (0);
	size = 0;
	ptr = stack;
	while (ptr)
	{
		ptr = ptr->next_node;
		size++;
	}
	return (size);
}

int is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next_node)
	{
		if (stack->value > stack->next_node->value)
			return (0);
		stack = stack->next_node;
	}
	return (1);
}

t_stack *smallest_node(t_stack *stack)
{
	t_stack *smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next_node;
	}
	return (smallest);
}
