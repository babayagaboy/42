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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// stack_innit.c

int		ft_check_repetition(t_stack *a, int nbr);
int		check_char(char *c);
void	ft_connect_node(t_stack **a, int nbr);
void	stack_innit(t_stack **a, long nbr);

// stack_utils.c

t_stack	*ft_lastnode(t_stack *stack);
int		ft_stacksize(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*smallest_node(t_stack *stack);
t_stack	*highest_node(t_stack *stack);

// rotate_cmd.c

int		rotate_cmd(t_stack **stack, char *mode);

// reverse_rotate_cmd.c

void	reverse_rotate_cmd(t_stack **stack, char *mode);

// swap_cmp.c

void	swap_cmd(t_stack **stack, char *mode);

// free_stack.c

void	free_stack(t_stack **stack);
void	free_exit(t_stack **stack);
void	free_array(char **array);

// push_cmd.c

int		push_cmd(t_stack **from, t_stack **to, char *mode);

// sort_three.c

void	sort_three(t_stack **a);
void	sort_small_a(t_stack **a, int len);
int		sort_small_b(t_stack **a, t_stack **b, int len);

// sort.c

void	sort(t_stack **a, t_stack **b);
int		get_pivot(t_stack *stack, int len);
int		quick_sort_stack_a(t_stack **a, t_stack **b, int len);
int		quick_sort_stack_b(t_stack **a, t_stack **b, int len);

// sort_utils.c

void	quick_sort_array(int *arr, int low, int high);
void	sort_if_three(t_stack **a, int len);
int		sort_stack_b(t_stack **a, t_stack **b, int pivot);

#endif