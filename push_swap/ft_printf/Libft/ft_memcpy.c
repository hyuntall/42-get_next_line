/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:49:32 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 18:15:19 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*tmp;
	const char		*str;

	i = 0;
	tmp = dst;
	str = src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	return (dst);
}
