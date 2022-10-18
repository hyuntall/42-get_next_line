/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:19:05 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:27:17 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_ptr;
	int		i;

	if (!s)
		return (0);
	s_ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_ptr)
		return (0);
	i = 0;
	while (s[i])
	{
		s_ptr[i] = f(i, s[i]);
		i++;
	}
	s_ptr[i] = '\0';
	return (s_ptr);
}
