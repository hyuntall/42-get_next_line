/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:59:40 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 19:21:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*make_new_shape(int	*arr, int gap)
{
	int	*new_shape;
	int	i;

	i = -1;
	new_shape = malloc(sizeof(int) * (gap + 1));
	new_shape[gap] = 0;
	while (++i < gap)
	{
		new_shape[i] = arr[i];
		new_shape[i] += arr[gap + i];
		new_shape[i] += arr[gap * 2 + i];
	}
	free(arr);
	return (new_shape);
}

void	make_direct(int n, int *arr, int direct, int index)
{
	if (n < 3)
	{
		if (direct)
			arr[index] = 1;
		else
			arr[index] = -1;
	}
	else
	{
		if (direct)
		{
			make_direct(n / 3, arr, 1, index);
			make_direct(n / 3, arr, 0, index + n / 3);
			make_direct(n / 3, arr, 0, index + n / 3 * 2);
		}
		else
		{
			make_direct(n / 3, arr, 1, index);
			make_direct(n / 3, arr, 1, index + n / 3);
			make_direct(n / 3, arr, 0, index + n / 3 * 2);
		}
	}
}
