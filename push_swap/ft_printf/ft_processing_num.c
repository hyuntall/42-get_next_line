/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:35:00 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/01 21:14:57 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(t_info *info, va_list ap)
{
	int			cnt;
	long long	num;
	int			side;

	info->base_num = 10;
	side = 0;
	num = va_arg(ap, int);
	if (num < 0)
	{
		info->sign = 0;
		num *= -1;
	}

	cnt = ft_lltoa(info, num);
	return (cnt);
}

int	ft_print_u(t_info *info, va_list ap)
{
	int			cnt;
	long long	num;

	info->base_num = 10;
	num = va_arg(ap, unsigned int);
	cnt = ft_lltoa(info, num);
	return (cnt);
}

int	ft_print_xX(t_info *info, va_list ap, char type)
{
	int			cnt;
	long long	num;

	info->base_num = 16;
	if (type == 'X')
		info->uppercase = -32;
	if (info->hash)
		info->address = 1;
	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		info->address = 0;
		cnt = ft_lltoa(info, num);
	}
	else if (num == -1)
		cnt = ft_print_num(info, "ffffffff");
	else
		cnt = ft_lltoa(info, num);
	return (cnt);
}

int	ft_print_p(t_info *info, va_list ap)
{
	int			cnt;
	long long	num;

	info->base_num = 16;
	info->address = 1;
	num = (unsigned long)va_arg(ap, void *);
	if (num == 0)
	{
		if (info->dot)
			cnt = ft_print_num(info, "0x");
		else
			cnt = ft_print_num(info, "0x0");
	}
	else if (num == -1)
		cnt = ft_print_num(info, "0xffffffffffffffff");
	else
		cnt = ft_lltoa(info, num);
	return (cnt);
}
