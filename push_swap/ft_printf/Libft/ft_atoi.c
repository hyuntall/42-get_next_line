/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:52:28 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/20 20:27:46 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 0 - sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
