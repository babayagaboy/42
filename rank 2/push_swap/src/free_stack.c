/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:38:59 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:40:20 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *next;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
	*stack = NULL;
}