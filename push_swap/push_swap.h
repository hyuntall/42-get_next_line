/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:43:59 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/17 19:35:58 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	struct s_node	*prev;
	int				num;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int			a_size;
	t_node		*a_top;
	t_node		*a_bottom;
	int			b_size;
	t_node		*b_top;
	t_node		*b_bottom;
}		t_stack;

#include "./ft_printf/Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "./ft_printf/Libft/ft_strlen.c"
#include "./ft_printf/Libft/ft_split.c"
#include "./ft_printf/Libft/ft_strjoin.c"
#include "./ft_printf/Libft/ft_strdup.c"


#include "./swap.c"
#include "./push.c"
#include "./rotate.c"
#include "./reverse_rotate.c"
#include "./print_error.c"
#include "./list_utils.c"
#include "./parse.c"
#include "./utils.c"
#include "./merge.c"
#include "./stack_sort.c"

int		count_num(char *str);
int		is_space(char c);
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

void	pusb_b(t_stack *stack);
void	pusb_a(t_stack *stack);

void	print_error(t_stack	*stack, char *str);
#endif