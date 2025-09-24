/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:47:27 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:47:28 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort_five(t_stack **a, t_stack **b)
{
	int size;
	int i;
	t_stack *smallest;

	size = ft_stacksize(*a);
	if (size <= 3)
	{
		sort_three(a);
		return ;
	}
	i = 0;
	while (size - i > 3)
	{
		smallest = smallest_node(*a);
		while ((*a)->value != smallest->value)
			rotate_cmd(a, "a");
		push_cmd(a, b, "b");
		i++;
	}
	sort_three(a);
	while (i-- > 0)
		push_cmd(b, a, "a");
}