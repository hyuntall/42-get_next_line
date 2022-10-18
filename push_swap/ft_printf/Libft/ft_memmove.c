/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:24:18 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/04 17:09:35 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*t_dst;
	unsigned const char	*t_src;

	i = -1;
	t_dst = dst;
	t_src = src;
	if ((t_dst == t_src) || len == 0)
		return (dst);
	if (dst < src)
		while (++i < len)
			t_dst[i] = t_src[i];
	else
		while (++i < len)
			t_dst[len - 1 - i] = t_src[len - 1 - i];
	return (dst);
}
