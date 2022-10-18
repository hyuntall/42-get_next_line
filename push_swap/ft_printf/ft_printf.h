/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:28:47 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/12 14:45:25 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BASE "0123456789abcdef"
# define XBASE "0123456789ABCDEF"

typedef struct _info{
	int			base_num;
	int			sign;
	int			address;
	int			uppercase;
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int			space;
	int			width;
	int			dot;
	int			precision;
}	t_info;

void			init_struct(t_info *info);
int				ft_printf(const char *format, ...);
int				parse_format(va_list ap, char *format);
int				ft_print_char(t_info *info, char c);
int				ft_print_str(t_info *info, char *s);
void			parse_flag(t_info *info, char **format);
void			parse_width(t_info *info, char **format, va_list ap);
void			parse_precision(t_info *info, char **format, va_list ap);
int				parse_type(t_info *info, va_list ap, char c);
int				ft_print_di(t_info *info, va_list ap);
int				ft_print_u(t_info *info, va_list ap);
int				ft_print_xX(t_info *info, va_list ap, char type);
int				ft_print_p(t_info *info, va_list ap);
int				ft_lltoa(t_info *info, long long num);
int				ft_print_num(t_info *info, char *s);
int				parse_atoi(char **s);
#endif
