/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:43:05 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 19:09:00 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_merge_l(t_stack *s, int ab, int bt, int bb)
{
	while (ab > 0 || bt > 0 || bb > 0)
	{
		if ((ab && !bt && !bb) || (ab && !bb && s->ab->n > s->bt->n) \
		|| (ab && s->ab->n > s->bt->n && s->ab->n > s->bb->n) || \
		(ab && !bt && s->ab->n > s->bb->n))
		{
			reverse_rotate_a(s);
			ab--;
		}
		else if ((!ab && bt && !bb) || (bt && !bb && s->bt->n > s->ab->n) \
		|| (bt && s->bt->n > s->ab->n && s->bt->n > s->bb->n) || \
		(bt && !ab && s->bt->n > s->bb->n))
		{
			push_a(s);
			bt--;
		}
		else if ((!ab && !bt && bb) || (bb && !bt && s->bb->n > s->ab->n) \
		|| (bb && s->bb->n > s->ab->n && s->bb->n > s->bt->n) || \
		(bb && !ab && s->bb->n > s->bt->n))
		{
			reverse_rotate_b(s);
			push_a(s);
			bb--;
		}
	}
}

void	down_merge_l(t_stack *s, int ab, int bt, int bb)
{
	while (ab > 0 || bt > 0 || bb > 0)
	{
		if ((ab && !bt && !bb) || (ab && !bb && s->ab->n < s->bt->n) \
		|| (ab && s->ab->n < s->bt->n && s->ab->n < s->bb->n) || \
		(ab && !bt && s->ab->n < s->bb->n))
		{
			reverse_rotate_a(s);
			ab--;
		}
		else if ((!ab && bt && !bb) || (bt && !bb && s->bt->n < s->ab->n) \
		|| (bt && s->bt->n < s->ab->n && s->bt->n < s->bb->n) || \
		(bt && !ab && s->bt->n < s->bb->n))
		{
			push_a(s);
			bt--;
		}
		else if ((!ab && !bt && bb) || (bb && !bt && s->bb->n < s->ab->n) \
		|| (bb && s->bb->n < s->ab->n && s->bb->n < s->bt->n) || \
		(bb && !ab && s->bb->n < s->bt->n))
		{
			reverse_rotate_b(s);
			push_a(s);
			bb--;
		}
	}
}

void	up_merge_r(t_stack *s, int bb, int at, int ab)
{
	while (bb > 0 || at > 0 || ab > 0)
	{
		if ((bb && !at && !ab) || (bb && !ab && s->bb->n > s->at->n) \
		|| (bb && s->bb->n > s->at->n && s->bb->n > s->ab->n) || \
		(bb && !at && s->bb->n > s->ab->n))
		{
			reverse_rotate_b(s);
			bb--;
		}
		else if ((!bb && at && !ab) || (at && !ab && s->at->n > s->bb->n) \
		|| (at && s->at->n > s->bb->n && s->at->n > s->ab->n) || \
		(at && !bb && s->at->n > s->ab->n))
		{
			push_b(s);
			at--;
		}
		else if ((!bb && !at && ab) || (ab && !at && s->ab->n > s->bb->n) \
		|| (ab && s->ab->n > s->bb->n && s->ab->n > s->at->n) || \
		(ab && !bb && s->ab->n > s->at->n))
		{
			reverse_rotate_a(s);
			push_b(s);
			ab--;
		}
	}
}

void	down_merge_r(t_stack *s, int bb, int at, int ab)
{
	while (bb > 0 || at > 0 || ab > 0)
	{
		if ((bb && !at && !ab) || (bb && !ab && s->bb->n < s->at->n) \
		|| (bb && s->bb->n < s->at->n && s->bb->n < s->ab->n) || \
		(bb && !at && s->bb->n < s->ab->n))
		{
			reverse_rotate_b(s);
			bb--;
		}
		else if ((!bb && at && !ab) || (at && !ab && s->at->n < s->bb->n) \
		|| (at && s->at->n < s->bb->n && s->at->n < s->ab->n) || \
		(at && !bb && s->at->n < s->ab->n))
		{
			push_b(s);
			at--;
		}
		else if ((!bb && !at && ab) || (ab && !at && s->ab->n < s->bb->n) \
		|| (ab && s->ab->n < s->bb->n && s->ab->n < s->at->n) || \
		(ab && !bb && s->ab->n < s->at->n))
		{
			reverse_rotate_a(s);
			push_b(s);
			ab--;
		}
	}
}

void	merge(t_stack *stack, int *shape, int gap, int lr)
{
	int		i;
	int		*tri_direct;

	tri_direct = malloc(sizeof(int) * (gap + 1));
	make_direct(gap, tri_direct, 1, 0);
	tri_direct[gap] = 0;
	i = -1;
	while (++i < gap)
	{
		if (tri_direct[i] > 0 && lr)
			up_merge_l(stack, shape[i], shape[gap + i], shape[2 * gap + i]);
		else if (tri_direct[i] < 0 && lr)
			down_merge_l(stack, shape[i], shape[gap + i], shape[2 * gap + i]);
		else if (tri_direct[i] > 0 && !lr)
			up_merge_r(stack, shape[i], shape[gap + i], shape[2 * gap + i]);
		else if (tri_direct[i] < 0 && !lr)
			down_merge_r(stack, shape[i], shape[gap + i], shape[2 * gap + i]);
	}
	free(tri_direct);
	tri_direct = 0;
}
