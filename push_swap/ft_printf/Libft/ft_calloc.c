/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:21:18 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 16:40:27 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (size && (count * size) / size != count)
		return (0);
	tmp = malloc(count * size);
	if (!tmp)
		return (0);
	ft_bzero(tmp, (count * size));
	return (tmp);
}
