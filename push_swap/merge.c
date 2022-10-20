/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:43:05 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/20 22:05:13 by hyuncpar         ###   ########.fr       */
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

void	up_merge(t_stack *stack, int ab, int bt, int bb)
{
	while (ab > 0 || bt > 0 || bb > 0)
	{
		if ((ab && stack->a_bottom->num > stack->b_top->num && stack->a_bottom->num > stack->b_bottom->num) || \
		(ab && !bt && stack->a_bottom->num > stack->b_bottom->num) || \
		(ab && !bb && stack->a_bottom->num > stack->b_top->num) || (ab && !bt && !bb))
		{
			reverse_rotate_a(stack);
			ab--;
		}
		else if ((bt && stack->b_top->num > stack->a_bottom->num && stack->b_top->num > stack->b_bottom->num) || \
		(bt && !ab && stack->b_top->num > stack->b_bottom->num) || \
		(bt && !bb && stack->b_top->num > stack->a_bottom->num) || (!ab && bt && !bb))
		{
			push_a(stack);
			bt--;
		}
		else if ((bb && stack->b_bottom->num > stack->a_bottom->num && stack->b_bottom->num > stack->b_top->num) || \
		(bb && !ab && stack->b_bottom->num > stack->b_top->num) || \
		(bb && !bt && stack->b_bottom->num > stack->a_bottom->num) || (!ab && !bt && bb))
		{
			reverse_rotate_b(stack);
			push_a(stack);
			bb--;
		}
	}
}

void	down_merge(t_stack *stack, int ab, int bt, int bb)
{
	while (ab > 0 || bt > 0 || bb > 0)
	{
		if ((ab && stack->a_bottom->num < stack->b_top->num && stack->a_bottom->num < stack->b_bottom->num) || \
		(ab && !bt && stack->a_bottom->num < stack->b_bottom->num) || \
		(ab && !bb && stack->a_bottom->num < stack->b_top->num) || (ab && !bt && !bb))
		{
			reverse_rotate_a(stack);
			ab--;
		}
		else if ((bt && stack->b_top->num < stack->a_bottom->num && stack->b_top->num < stack->b_bottom->num) || \
		(bt && !ab && stack->b_top->num < stack->b_bottom->num) || \
		(bt && !bb && stack->b_top->num < stack->a_bottom->num) || (!ab && bt && !bb))
		{
			push_a(stack);
			bt--;
		}
		else if ((bb && stack->b_bottom->num < stack->a_bottom->num && stack->b_bottom->num < stack->b_top->num) || \
		(bb && !ab && stack->b_bottom->num < stack->b_top->num) || \
		(bb && !bt && stack->b_bottom->num < stack->a_bottom->num) || (!ab && !bt && bb))
		{
			reverse_rotate_b(stack);
			push_a(stack);
			bb--;
		}
	}
}

void	merge(t_stack *stack, int *shape, int gap)
{
	int		i;
	int		a;
	int		b;
	int		c;

	i = -1;
	if (++i < 1)
	{
		printf("gap:%d %d\n", shape[gap], gap);
		a = shape[i];
		b = shape[gap + i];
		c = shape[2 * gap + i++];
		up_merge(stack, a, b, c);
		//print_stack(stack);
		printf("%d %d %d\n", a, b, c);
		a = shape[i];
		b = shape[gap + i];
		c = shape[2 * gap + i++];
		down_merge(stack, a, b, c);
		//print_stack(stack);
		printf("%d %d %d\n", a, b, c);
		a = shape[i];
		b = shape[gap + i];
		c = shape[2 * gap + i];
		down_merge(stack, a, b, c);
		//print_stack(stack);
		printf("%d %d %d\n", a, b, c);
	}
}