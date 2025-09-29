/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:38:48 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 12:38:48 by hgutterr         ###   ########.fr       */
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
	int	index;
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
int is_sorted(t_stack *stack);
t_stack *smallest_node(t_stack *stack);
t_stack *highest_node(t_stack *stack);

// rotate_cmd.c

void	rotate_cmd(t_stack **stack, char *mode);

// reverse_rotate_cmd.c

void reverse_rotate_cmd(t_stack **stack, char *mode);

// swap_cmp.c

void	swap_cmd(t_stack **stack, char *mode);

// free_stack.c

void	free_stack(t_stack **stack);

// push_cmd.c

void push_cmd(t_stack **from, t_stack **to, char *mode);

// sort_three.c

void sort_three(t_stack **a);
void sort_small_b(t_stack **a, t_stack **b, int len);

// sort_five.c

void sort_five(t_stack **a, t_stack **b);

// sort.c

void sort(t_stack **a, t_stack **b);
int  get_pivot(t_stack *stack, int len);
void quick_sort_stack_a(t_stack **a, t_stack **b, int len);
void        quick_sort_stack_b(t_stack **a, t_stack **b, int len);

// sort_utils.c

void    quick_sort_array(int *arr, int low, int high);

void sort_small_a(t_stack **a, int len);

#endif