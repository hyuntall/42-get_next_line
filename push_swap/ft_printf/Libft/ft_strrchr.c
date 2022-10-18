/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:43:57 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:30:07 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	tmp;
	size_t	i;

	str = (char *)s;
	tmp = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == tmp)
			return (str + i);
		i--;
	}
	if (str[i] == tmp)
		return (str);
	return (0);
}
