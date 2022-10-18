/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:29:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/17 15:28:01 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init(t_stack *stack)
{
	stack->a_size = 0;
	stack->a_top = 0;
	stack->a_bottom = 0;
	stack->b_size = 0;
	stack->b_top = 0;
	stack->b_bottom = 0;
}

void	small_size_sort(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a_top->num;
	second = stack->a_top->next->num;
	third = stack->a_bottom->num;
	if (third > first && first > second)
		swap_a(stack);
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first > third && third > second)
		rotate_a(stack);
	else if (second > third && third > first)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else
		reverse_rotate_a(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init(&stack);
	if (!argv_to_stack(&stack, ++argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (stack_is_sort(&stack))
	{
		clear_stack(&stack);
		return (0);
	}
	if (stack.a_size == 2)
		swap_a(&stack);
	else if (stack.a_size == 3)
		small_size_sort(&stack);
	else
		stack_sort(&stack);
	//system("leaks a.out");
	return (0);
}