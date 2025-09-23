/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:45:59 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/16 16:45:59 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

t_stack	*ft_lastnode(t_stack *ptr)
{
	if (!ptr)
		return (NULL);
	while (ptr->next_node)
		ptr = ptr->next_node;
	return (ptr);
}