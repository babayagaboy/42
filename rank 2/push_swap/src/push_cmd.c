/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:22:54 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:22:54 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void push_cmd(t_stack **from, t_stack **to, char *mode)
{
    t_stack *tmp;
    if (!from || !*from)
        return;
    tmp = *from;
    *from = tmp->next_node;
    if (*from)
        (*from)->prev_node = NULL;
    tmp->next_node = *to;
    if (*to)
        (*to)->prev_node = tmp;
    tmp->prev_node = NULL;
    *to = tmp;

	if (mode)
		ft_printf("p%s\n", mode);
}