/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:47:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/07/27 15:47:09 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	long long		nb;
	int				len;

	len = nbr_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	nb = n;
	result[len--] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		result[0] = '0';
	while (nb)
	{
		result[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
