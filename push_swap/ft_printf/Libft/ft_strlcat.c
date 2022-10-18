/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:44:50 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:23:22 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (dstsize < i)
		return (dstsize + j);
	while (src[k] && i + k + 1 < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}
