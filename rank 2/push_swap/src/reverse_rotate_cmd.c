/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:28:55 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/30 12:52:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_cmd(t_stack **stack, char *mode)
{
	t_stack		*first_node;
	t_stack		*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last_node = ft_lastnode(*stack);
	first_node = *stack;
	*stack = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	if (mode)
		ft_printf("rr%s\n", mode);
}
