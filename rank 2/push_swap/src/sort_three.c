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

void	sort_three(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	if (ft_stacksize(*a) != 3)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_cmd(a, "a");
	else if (first > second && second > third && first > third)
	{
		swap_cmd(a, "a");
		reverse_rotate_cmd(a, "a");
	}
	else if (first > second && second < third && first > third)
		rotate_cmd(a, "a");
	else if (first < second && second > third && first < third)
	{
		swap_cmd(a, "a");
		rotate_cmd(a, "a");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_cmd(a, "a");
}

int	sort_small_b(t_stack **a, t_stack **b, int len)
{
	if (len == 1)
		push_cmd(b, a, "a");
	else if (len == 2)
	{
		if ((*b)->value < (*b)->next->value)
			swap_cmd(b, "b");
		push_cmd(b, a, "a");
		push_cmd(b, a, "a");
	}
	else if (len == 3)
	{
		if ((*b)->value < (*b)->next->value)
			swap_cmd(b, "b");
		push_cmd(b, a, "a");
		if ((*b)->value < (*b)->next->value)
			swap_cmd(b, "b");
		push_cmd(b, a, "a");
		if ((*a)->value > (*a)->next->value)
			swap_cmd(a, "a");
		push_cmd(b, a, "a");
		if ((*a)->value > (*a)->next->value)
			swap_cmd(a, "a");
	}
	return (0);
}

void	sort_small_a(t_stack **a, int len)
{
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			swap_cmd(a, "a");
	}
	else if (len == 3)
	{
		if ((*a)->next->next->value > (*a)->next->value
			&& (*a)->next->value > (*a)->value)
			return ;
		if ((*a)->next->next->value > (*a)->value)
			swap_cmd(a, "a");
		else
		{
			swap_cmd(a, "a");
			rotate_cmd(a, "a");
			swap_cmd(a, "a");
			reverse_rotate_cmd(a, "a");
		}
	}
}
