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

int	push_cmd(t_stack **from, t_stack **to, char *mode)
{
	t_stack		*tmp;

	if (!from || !*from)
		return (0);
	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	tmp->prev = NULL;
	*to = tmp;
	if (mode)
		ft_printf("p%s\n", mode);
	return (1);
}
