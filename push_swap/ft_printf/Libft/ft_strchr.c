/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:54:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:14:36 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == tmp)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
