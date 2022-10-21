/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:51 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 20:39:19 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_start(t_stack *stack, int *shape, int gap)
{
	int	cnt;
	int	tmp;
	int	i;

	i = 1;
	while (gap > 0)
	{
		cnt = 0;
		tmp = 0;
		while (cnt < gap)
			tmp += shape[cnt++];
		if (i % 2)
			while (tmp--)
				push_a(stack);
		else
			while (tmp--)
				push_b(stack);
		merge(stack, shape, gap, i % 2);
		shape = make_new_shape(shape, gap);
		i++;
		gap /= 3;
	}
}

void	stack_sort(t_stack *stack)
{
	int		*shape;
	int		gap;
	int		tmp;

	gap = 1;
	shape = tri_shape(stack->as);
	if (!shape)
		print_error(stack, "malloc error");
	tmp = stack->as;
	while (tmp / 3 > 5)
	{
		gap *= 3;
		tmp /= 3;
	}
	make_triangle(stack, shape, 1, gap);
	merge_start(stack, shape, gap);
	//print_stack(stack);
}
