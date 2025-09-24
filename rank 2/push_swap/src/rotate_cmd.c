/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:44:12 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/16 16:44:12 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void rotate_cmd(t_stack **stack, char *mode)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	first_node = *stack;
	last_node = ft_lastnode(*stack);
	*stack = first_node->next_node;
	(*stack)->prev_node = NULL;
	last_node->next_node = first_node;
	first_node->prev_node = last_node;
	first_node->next_node = NULL;

	if (mode)
		ft_printf("r%s\n", mode);
}
