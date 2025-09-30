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

void	quick_sort_array(int *arr, int low, int high)
{
	int		i;
	int		j;
	int		pivot;
	int		tmp;

	if (low >= high)
		return ;
	pivot = arr[high];
	i = low - 1;
	j = low - 1;
	while (++j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	quick_sort_array(arr, low, i);
	quick_sort_array(arr, i + 2, high);
}

void	sort_if_three(t_stack **a, int len)
{
	if (len == 2 && (*a)->value > (*a)->next->value)
		swap_cmd(a, "a");
	else if (ft_stacksize(*a) <= 3)
	{
		sort_three(a);
	}
	else if (len == 3)
		sort_small_a(a, len);
}

int	sort_stack_b(t_stack **a, t_stack **b, int pivot)
{
	if ((*a)->next && (*a)->value > (*a)->next->value)
		swap_cmd(a, "a");
	if ((*b)->value > pivot)
	{
		if ((*a)->next && (*a)->value > (*a)->next->value)
			swap_cmd(a, "a");
		if ((*b)->value < (*b)->next->value)
			swap_cmd(b, "b");
		return (push_cmd(b, a, "a") + 1);
	}
	else
		return (rotate_cmd(b, "b"));
	return (1);
}
