/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:43:59 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 18:27:16 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	i = 0;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (0);
	while (++j < ft_strlen(s1))
	{
		tmp[i] = s1[j];
		i++;
	}
	j = -1;
	while (++j < ft_strlen(s2))
	{
		tmp[i] = s2[j];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
