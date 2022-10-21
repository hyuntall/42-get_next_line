/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:59:08 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 20:32:59 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_target(t_stack *stack, int target)
{
	if (target == stack->at->n)
		push_b(stack);
	else if (target == stack->at->next->n)
	{
		swap_a(stack);
		push_b(stack);
	}
	else if (target == stack->ab->n)
	{
		reverse_rotate_a(stack);
		push_b(stack);
	}
	else if (target == stack->at->next->next->n)
	{
		rotate_a(stack);
		swap_a(stack);
		push_b(stack);
		//reverse_rotate_a(stack);
	}
	else if (target == stack->ab->prev->n)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
		push_b(stack);
	}
}

void	up_tri(t_stack *stack, int goal)
{
	int	target;
	int	tmp;

	tmp = 2147483647;
	while (stack->bs < goal)
	{
		target = -2147483648;
		if (stack->at->n <= tmp)
			target = stack->at->n;
		if (stack->at->next->n <= tmp && stack->at->next->n >= target)
			target = stack->at->next->n;
		if (stack->ab->n <= tmp && stack->ab->n >= target)
			target = stack->ab->n;
		if (stack->as > 4 && stack->at->next->next->n <= tmp && \
		stack->at->next->next->n >= target)
			target = stack->at->next->next->n;
		if (stack->as > 3 && stack->ab->prev->n <= tmp && \
		stack->ab->prev->n >= target)
			target = stack->ab->prev->n;
		move_target(stack, target);
		if (stack->as == 1)
			push_b(stack);
		tmp = target;
	}
}

void	down_tri(t_stack *stack, int goal)
{
	int	target;
	int	tmp;

	tmp = -2147483648;
	while (stack->bs < goal)
	{
		target = 2147483647;
		if (stack->at->n >= tmp)
			target = stack->at->n;
		if (stack->at->next->n >= tmp && stack->at->next->n <= target)
			target = stack->at->next->n;
		if (stack->ab->n >= tmp && stack->ab->n <= target)
			target = stack->ab->n;
		if (stack->as > 4 && stack->at->next->next->n >= tmp && \
		stack->at->next->next->n <= target)
			target = stack->at->next->next->n;
		if (stack->as > 3 && stack->ab->prev->n >= tmp && \
		stack->ab->prev->n <= target)
			target = stack->ab->prev->n;
		move_target(stack, target);
		tmp = target;
		if (stack->as == 1)
			push_b(stack);
	}
}

void	make_triangle(t_stack *stack, int *shape, int direct, int size)
{
	if (size < 1)
	{
		if (direct)
			up_tri(stack, stack->bs + *shape);
		else
			down_tri(stack, stack->bs + *shape);
	}
	else
	{
		if (direct)
		{
			make_triangle(stack, shape, 1, size / 3);
			make_triangle(stack, shape + size, 0, size / 3);
			make_triangle(stack, shape + size * 2, 0, size / 3);
		}
		else
		{
			make_triangle(stack, shape, 1, size / 3);
			make_triangle(stack, shape + size, 1, size / 3);
			make_triangle(stack, shape + size * 2, 0, size / 3);
		}
	}
}
