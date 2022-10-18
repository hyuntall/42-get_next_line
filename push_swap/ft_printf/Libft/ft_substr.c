/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:28:43 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:36:30 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (++i < len && s[start + i])
		tmp[i] = s[start + i];
	tmp[i] = '\0';
	return (tmp);
}
