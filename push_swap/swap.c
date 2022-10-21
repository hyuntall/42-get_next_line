/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:03:20 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 15:44:03 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
	write(1, "sb\n", 3);
}

void	swap_all(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->at->n;
	second = stack->at->next->n;
	stack->at->n = second;
	stack->at->next->n = first;
	first = stack->bt->n;
	second = stack->bt->next->n;
	stack->bt->n = second;
	stack->bt->next->n = first;
	write(1, "ss\n", 3);
}
