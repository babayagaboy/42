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

void	sort(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_stacksize(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 3)
		sort_three(a);
	else
		quick_sort_stack_a(a, b, size);
}

int	get_pivot(t_stack *stack, int len)
{
	t_stack		*tmp;
	int			*arr;
	int			i;
	int			pivot;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp && i < len)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quick_sort_array(arr, 0, len - 1);
	pivot = arr[len / 2];
	free(arr);
	return (pivot);
}

int	quick_sort_stack_a(t_stack **a, t_stack **b, int len)
{
	int		pivot;
	int		i;
	int		pushed;
	int		ra_count;

	if (len <= 3)
		return (sort_if_three(a, len), 0);
	pivot = get_pivot(*a, len);
	i = 0;
	pushed = 0;
	ra_count = 0;
	while (i < len)
	{
		if ((*a)->value < pivot)
			pushed += push_cmd(a, b, "b");
		else
			ra_count += rotate_cmd(a, "a");
		i++;
	}
	while (ra_count--)
		reverse_rotate_cmd(a, "a");
	quick_sort_stack_a(a, b, len - pushed);
	quick_sort_stack_b(a, b, pushed);
	return (0);
}

int	quick_sort_stack_b(t_stack **a, t_stack **b, int len)
{
	int		pivot;
	int		i;
	int		pushed;
	int		rb_count;

	if (len <= 3)
		return (sort_small_b(a, b, len));
	pivot = get_pivot(*b, len);
	i = 0;
	pushed = 0;
	rb_count = 0;
	while (i < len)
	{
		if (sort_stack_b(a, b, pivot) == 1)
			rb_count++;
		else
			pushed++;
		i++;
	}
	while (rb_count--)
		reverse_rotate_cmd(b, "b");
	quick_sort_stack_a(a, b, pushed + 1);
	quick_sort_stack_b(a, b, len - pushed);
	return (0);
}
