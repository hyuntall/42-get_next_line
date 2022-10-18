/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:50:02 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/01 21:15:15 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(t_info *info, long long nbr)
{
	int	len;	

	len = 0;
	if (nbr == 0)
		return (1);
	else if (info->sign == -1)
		len++;
	while (nbr != 0)
	{
		nbr /= info->base_num;
		len++;
	}
	return (len);
}

void	fill_array(t_info *info, long long num, char **result, int len)
{
	char	*base;

	if (info->uppercase)
		base = XBASE;
	else
		base = BASE;
	while (num)
	{
		(*result)[len--] = base[num % info->base_num];
		num /= info->base_num;
	}
	while (len > -1)
		(*result)[len--] = '0';
	if (info->address == 1)
	{
		(*result)[1] = 'x' + info->uppercase;
		(*result)[0] = '0';
	}
	if (!info->sign)
		(*result)[0] = '-';
	else if (info->sign && info->plus)
		(*result)[0] = '+';
	else if (info->space)
		(*result)[0] = ' ';
}

int	ft_print_num(t_info *info, char *s)
{
	int		result;
	int		len;
	char	c;

	c = ' ';
	len = ft_strlen(s);
	if ((len > 0 && info->precision > len) \
	|| (info->zero && info->precision > len))
		c = '0';
	if (s == NULL)
		s = "(null)";
	result = 0;
	if (!info->minus)
		while (info->width-- > len)
			result += write(1, &c, 1);
	while (len-- > 0)
	{
		result += write(1, s++, 1);
		info->width--;
	}
	while (info->width-- > 0)
		result += write(1, " ", 1);
	return (result);
}

int	ft_lltoa(t_info *info, long long num)
{
	char	*result;
	int		len;
	int		cnt;

	len = nbr_len(info, num);
	if ((info->dot && info->precision > len) \
	|| (info->dot && info->precision == 0 && num == 0))
		len = info->precision;
	if (!info->sign || (info->sign && info->plus) || info->space)
		len += 1;
	if (info->address)
		len += 2;
	if ((info->dot && info->precision < 0 && info->zero && info->width > len) \
	|| (info->zero && info->width > len && !info->dot))
		len = info->width;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = '\0';
	if (num == 0)
		result[len--] = '0';
	fill_array(info, num, &result, len);
	cnt = ft_print_num(info, result);
	free(result);
	return (cnt);
}
