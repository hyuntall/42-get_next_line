/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:43:05 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/18 22:45:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_merge_left(t_stack *stack, int size, int LR)
{
	int	a;
	int	b;
	int	c;
	size = 0;
	LR = 0;
	a = 3;
	b = 3;
	c = 3;
	print_stack(stack);
	while (a && b && c)
	{
		if (stack->a_bottom->num > stack->b_top->num && stack->a_bottom->num > stack->b_bottom->num)
		{
			reverse_rotate_a(stack);
			a--;
		}
		else if (stack->b_top->num > stack->a_bottom->num && stack->b_top->num > stack->b_bottom->num)
		{
			push_a(stack);
			b--;
		}
		else if (stack->b_bottom->num > stack->a_bottom->num && stack->b_bottom->num > stack->b_top->num)
		{
			reverse_rotate_b(stack);
			push_a(stack);
			c--;
		}
		printf("a: %d b: %d c: %d\n", stack->a_bottom->num, stack->b_bottom->num, stack->b_top->num);
	}
	printf("a: %d b: %d c: %d\n", a, b, c);
	print_stack(stack);
	while ((!a && b && c) || (a && !b && c) || (a && b && !c))
	{
		printf("a: %d b: %d c: %d\n", a, b, c);
		if (!a && b && c)
		{
			if (stack->b_top->num > stack->a_bottom->num)
			{
				push_a(stack);
				b--;
			}
			else
			{
				reverse_rotate_b(stack);
				push_a(stack);
				c--;
			}
		}
		else if (a && !b && c)
		{
			if (stack->a_bottom->num > stack->b_bottom->num)
			{
				reverse_rotate_a(stack);
				a--;
			}
			else
			{
				reverse_rotate_b(stack);
				push_a(stack);
				c--;
			}
		}
		else if (a && b && !c)
		{
			if (stack->a_bottom->num > stack->b_top->num)
			{
				reverse_rotate_a(stack);
				a--;
			}
			else
			{
				push_a(stack);
				b--;
			}
		}
	}
	printf("a: %d b: %d c: %d\n", a, b, c);
	print_stack(stack);
	while (a)
	{
		reverse_rotate_a(stack);
		a--;
	}
	while (b)
	{
		push_a(stack);
		b--;
	}
	while (c)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		c--;
	}
	print_stack(stack);
}