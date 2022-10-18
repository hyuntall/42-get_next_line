/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:13 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:57:34 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *) haystack);
	if (!ft_strlen(haystack) || ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *) &haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
