/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:59:21 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:59:21 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort(t_stack **a, t_stack **b)
{
	int size;

	size = ft_stacksize(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		index_stack(a);
		chunk_sort(a, b);
	}
}

void chunk_sort(t_stack **a, t_stack **b)
{
	int stack_len;
	int chunk_size;

	stack_len = ft_stacksize(*a);
	chunk_size = get_chunk_size(stack_len);
	push_chunks_to_b(a, b, chunk_size, stack_len);
	push_back_to_a(a, b);
}

void push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size, int stack_len)
{
    int chunk_start = 0;
    int chunk_end = chunk_size;
    int i;

    while (chunk_start < stack_len)
    {
        i = 0;
        while (i < stack_len && *a)
        {
            if ((*a)->index >= chunk_start && (*a)->index < chunk_end)
                push_cmd(a, b, "b");
            else
                rotate_cmd(a, "a");
            i++;
        }
        chunk_start += chunk_size;
        chunk_end += chunk_size;
        if (chunk_end > stack_len)
            chunk_end = stack_len;
    }
}


void push_back_to_a(t_stack **a, t_stack **b)
{
    int max_idx;
    while (*b)
    {
        max_idx = find_max_index(*b);
        while ((*b)->index != max_idx)
            rotate_cmd(b, "b");
        push_cmd(b, a, "a");
    }
}