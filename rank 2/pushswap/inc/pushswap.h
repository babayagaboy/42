/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:06:06 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/15 19:06:06 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int	value;
	int	position;
	struct s_stack *next_node;
	struct s_stack *prev_node;
}	t_stack;

// stack_innit.c

int		ft_check_repetition(t_stack *a, int nbr);
void	ft_connect_node(t_stack **a, int nbr);
void	stack_innit(t_stack **a, char **argv);

// stack_utils.c

t_stack	*ft_lastnode(t_stack *stack);
int	ft_stacksize(t_stack *stack);

// rotate_cmd.c

void	rotate_cmd(t_stack **stack);

// reverse_rotate_cmd.c

void reverse_rotate_cmd(t_stack **stack);

// swap_cmp.c

void	swap_cmd(t_stack **stack);

// free_stack.c

void	free_stack(t_stack **stack);

#endif