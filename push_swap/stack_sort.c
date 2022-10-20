/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:51 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/20 22:02:23 by hyuncpar         ###   ########.fr       */
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

void	fill_arr(int n, int *arr, int index, int gap)
{
	if (n / 3 < 6)
	{
		*arr = n / 3;
		*(arr + gap) = n / 3 + n % 3;
		*(arr + gap * 2) = n / 3;
	}
	else
	{
		fill_arr(n / 3, arr, index / 3, gap);
		fill_arr(n / 3 + n % 3, arr + index / 3, index / 3, gap);
		fill_arr(n / 3, arr + index / 3 * 2, index / 3, gap);
	}
}

int	*tri_shape(int size)
{
	int		len;
	int		temp;
	int		*arr;

	len = 1;
	temp = size;
	while (temp > 5)
	{
		len *= 3;
		temp /= 3;
	}
	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (0);
	fill_arr(size, arr, len / 3, len / 3);
	arr[len] = 0;
	return (arr);
}

void	make_triangle(t_stack *stack, int *shape, int direct, int size)
{
	if (size < 1)
	{
		if (direct)
			up_tri(stack, stack->b_size + *shape);
		else
			down_tri(stack, stack->b_size + *shape);
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

void	stack_sort(t_stack *stack)
{
	int		*shape;
	int		gap;
	int		tmp;
	int		i;

	gap = 1;
	shape = tri_shape(stack->a_size);
	if (!shape)
		print_error(stack, "malloc error");
	tmp = stack->a_size;
	while (tmp > 5)
	{
		gap *= 3;
		tmp /= 3;
	}
	gap /= 3;
	i = gap;
	tmp = 0;
	make_triangle(stack, shape, 1, gap);
	while (i > 0)
		tmp += shape[--i];
	while (tmp--)
		push_a(stack);
	//print_stack(stack);
	merge(stack, shape, gap);
	//print_stack(stack);
	//free(shape);
	printf("exit\n");
}
