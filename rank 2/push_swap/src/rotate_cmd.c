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

int	rotate_cmd(t_stack **stack, char *mode)
{
	t_stack		*first_node;
	t_stack		*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first_node = *stack;
	last_node = ft_lastnode(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	if (mode)
		ft_printf("r%s\n", mode);
	return (1);
}
