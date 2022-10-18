/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:54:41 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/01 21:15:33 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_info *info, char c)
{
	int		result;
	char	space;

	space = ' ';
	if (info->zero)
		space = '0';
	result = 0;
	if (!info->minus)
	{
		while (--info->width > 0)
			result += write(1, &space, 1);
	}
	result += write(1, &c, 1);
	while (--info->width > 0)
		result += write(1, " ", 1);
	return (result);
}

int	ft_print_str(t_info *info, char *s)
{
	int	result;
	int	len;

	if (s == NULL)
		s = "(null)";
	result = 0;
	len = ft_strlen(s);
	if (info->dot && info->precision < len && info->precision > -1)
		len = info->precision;
	if (!info->minus)
		while (info->width-- > len)
			result += write(1, " ", 1);
	while (len-- > 0)
	{
		result += write(1, s++, 1);
		info->width--;
	}
	while (info->width-- > 0)
		result += write(1, " ", 1);
	return (result);
}
