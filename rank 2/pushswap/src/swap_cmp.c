/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:15:43 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/23 13:26:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	swap_cmd(t_stack **stack)
{
	t_stack *first_node;
	t_stack *second_node;
	if (!stack || !(*stack) || !(*stack)->next_node)
		return ;
	first_node = *stack;
	second_node = first_node->next_node;
	first_node->next_node = second_node->next_node;
	if (second_node->next_node)
		second_node->next_node->prev_node = first_node;
	second_node->prev_node = NULL;
	second_node->next_node = first_node;
	first_node->prev_node = second_node;
	*stack = second_node;
}