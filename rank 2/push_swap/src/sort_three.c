/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:28:46 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:28:46 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	if (ft_stacksize(*a) != 3)
		return;
	first = (*a)->value;
	second = (*a)->next_node->value;
	third = (*a)->next_node->next_node->value;
	if(first > second && second < third && first < third)
		swap_cmd(a, "a");
	else if(first > second && second > third && first > third)
	{
		swap_cmd(a, "a");
		reverse_rotate_cmd(a, "a");
	}
	else if(first > second && second < third && first > third)
		rotate_cmd(a, "a");
	else if(first < second && second > third && first < third)
	{
		swap_cmd(a, "a");
		rotate_cmd(a, "a");
	}
	else if(first < second && second > third && first > third)
		reverse_rotate_cmd(a, "a");
}
