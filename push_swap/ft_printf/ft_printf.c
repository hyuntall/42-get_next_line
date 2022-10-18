/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:50:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/01 21:13:21 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_info *info)
{
	info->address = 0;
	info->base_num = 10;
	info->sign = 1;
	info->uppercase = 0;
	info->minus = 0;
	info->plus = 0;
	info->zero = 0;
	info->hash = 0;
	info->space = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = 0;
}

int	parse_format(va_list ap, char *format)
{
	t_info	info;
	int		result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_struct(&info);
			parse_flag(&info, &format);
			parse_width(&info, &format, ap);
			parse_precision(&info, &format, ap);
			result += parse_type(&info, ap, *format);
		}
		else
			result += write(1, format, 1);
		format++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}
