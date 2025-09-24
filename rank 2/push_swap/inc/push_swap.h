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

// sort_five.c

void sort_five(t_stack **a, t_stack **b);

// sort.c

void sort(t_stack **a, t_stack **b);
void chunk_sort(t_stack **a, t_stack **b);
void push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size, int stack_len);
void push_back_to_a(t_stack **a, t_stack **b);

// sort_utils.c

void index_stack(t_stack **stack);
int get_chunk_size(int stack_len);
int find_max_index(t_stack *b);

#endif