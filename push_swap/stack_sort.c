/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:51 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/18 22:42:28 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_target(t_stack *stack, int target)
{
	if (target == stack->a_top->num)
		push_b(stack);
	else if (target == stack->a_top->next->num)
	{
		swap_a(stack);
		push_b(stack);
	}
	else if (target == stack->a_bottom->num)
	{
		reverse_rotate_a(stack);
		push_b(stack);
	}
	else if (target == stack->a_top->next->next->num)
	{
		rotate_a(stack);
		swap_a(stack);
		push_b(stack);
		reverse_rotate_a(stack);
	}
	else if (target == stack->a_bottom->prev->num)
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
	while (stack->b_size < goal)
	{
		target = -2147483648;
		if (stack->a_top->num <= tmp)
			target = stack->a_top->num;
		if (stack->a_top->next->num <= tmp && stack->a_top->next->num >= target)
			target = stack->a_top->next->num;
		if (stack->a_bottom->num <= tmp && stack->a_bottom->num >= target)
			target = stack->a_bottom->num;
		if (stack->a_size > 4 && stack->a_top->next->next->num <= tmp && \
		stack->a_top->next->next->num >= target)
			target = stack->a_top->next->next->num;
		if (stack->a_size > 3 && stack->a_bottom->prev->num <= tmp && \
		stack->a_bottom->prev->num >= target)
			target = stack->a_bottom->prev->num;
		move_target(stack, target);
		if (stack->a_size == 1)
			push_b(stack);
		tmp = target;
	}
}

void	down_tri(t_stack *stack, int goal)
{
	int	target;
	int	tmp;

	tmp = -2147483648;
	while (stack->b_size < goal)
	{
		target = 2147483647;
		if (stack->a_top->num >= tmp)
			target = stack->a_top->num;
		if (stack->a_top->next->num >= tmp && stack->a_top->next->num <= target)
			target = stack->a_top->next->num;
		if (stack->a_bottom->num >= tmp && stack->a_bottom->num <= target)
			target = stack->a_bottom->num;
		if (stack->a_size > 4 && stack->a_top->next->next->num >= tmp && \
		stack->a_top->next->next->num <= target)
			target = stack->a_top->next->next->num;
		if (stack->a_size > 3 && stack->a_bottom->prev->num >= tmp && \
		stack->a_bottom->prev->num <= target)
			target = stack->a_bottom->prev->num;
		move_target(stack, target);
		tmp = target;
		if (stack->a_size == 1)
			push_b(stack);
	}
}

void	make_triangle(t_stack *stack, int size, int direct)
{
	if (size < 6)
	{
		if (direct)
			up_tri(stack, stack->b_size + size);
		else
			down_tri(stack, stack->b_size + size);
	}
	else
	{
		if (direct)
		{
			make_triangle(stack, size / 3, 1);
			make_triangle(stack, size / 3 + size % 3, 0);
			make_triangle(stack, size / 3, 0);
		}
		else
		{
			make_triangle(stack, size / 3, 1);
			make_triangle(stack, size / 3 + size % 3, 1);
			make_triangle(stack, size / 3, 0);
		}
	}
}

void	stack_sort(t_stack *stack)
{
	t_node	*node;

	printf("atop: %d\n", stack->a_top->num);
	printf("abottom: %d\n", stack->a_bottom->num);
	printf("asize: %d\n", stack->a_size);
	node = stack->a_top;
	make_triangle(stack, stack->a_size, 1);
	int cnt = stack->b_size / 3;
	int size = stack->b_size;
	printf("%d\n", size / 3);
	while (cnt-- > 0)
		push_a(stack);
	print_stack(stack);
	up_merge_left(stack, size / 9, 1);
	print_stack(stack);
	cnt = 1;
	printf("exit\n");
}