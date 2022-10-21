/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:43:59 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 20:38:25 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	struct s_node	*prev;
	int				n;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int			as;
	t_node		*at;
	t_node		*ab;
	int			bs;
	t_node		*bt;
	t_node		*bb;
}		t_stack;

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
#include "./ft_printf/Libft/ft_strlen.c"
#include "./ft_printf/Libft/ft_split.c"
#include "./ft_printf/Libft/ft_strjoin.c"
#include "./ft_printf/Libft/ft_strdup.c"
*/
/*
#include "./swap.c"
#include "./push.c"
#include "./rotate.c"
#include "./reverse_rotate.c"
#include "./print_error.c"
#include "./list_utils.c"
#include "./parse.c"
#include "./utils.c"
#include "./make_arr.c"
#include "./merge.c"
#include "./make_tri.c"
#include "./stack_sort.c"
*/
int		count_num(char *str);
int		ft_atoll(t_stack *stack, char *str);
int		count_num(char *str);
char	*join_argv(t_stack *stack, char **argv);
int		argv_to_stack(t_stack *stack, char **argv);

t_node	*ft_lstnew(int value);
int		is_unique_list(t_stack *stack, int target);
void	first_insert(t_stack *stack, int num);
void	node_insert(t_stack *stack, int num);
void	node_remove(t_node *node);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_all(t_stack *stack);

void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_all(t_stack *stack);

void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_all(t_stack *stack);

void	stack_sort(t_stack *stack);

void	merge(t_stack *stack, int *shape, int gap, int lr);

int		*make_new_shape(int	*arr, int gap);
int		*tri_shape(int size);
void	make_direct(int n, int *arr, int direct, int index);

void	clear_stack(t_stack *stack);
void	print_error(t_stack	*stack, char *str);

void	make_triangle(t_stack *stack, int *shape, int direct, int size);

int		stack_is_sort(t_stack *stack);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	print_stack(t_stack *stack);
#endif