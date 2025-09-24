/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:16:51 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 13:16:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void index_stack(t_stack **stack)
{
	t_stack *ptr;
	t_stack *current;
	int index;

	ptr = *stack;
	while (ptr)
	{
		index = 0;
		current = *stack;
		while (current)
		{
			if (ptr->value > current->value)
				index++;
			current = current->next_node;
		}
		ptr->index = index;
		ptr = ptr->next_node;
	}
}

int get_chunk_size(int stack_len)
{
	if (stack_len <= 100)
		return stack_len / 5; // 5 chunks
	else
		return stack_len / 11; // ~45 chunks for 500
}

int find_max_index(t_stack *b)
{
    int max = b->index;
    while (b)
    {
        if (b->index > max)
            max = b->index;
        b = b->next_node;
    }
    return max;
}