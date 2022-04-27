/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:05:59 by donchoi           #+#    #+#             */
/*   Updated: 2022/04/27 16:51:33 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c)
{
	int	len;

	len = ft_putchar_fd(c, 1);
	return (len);
}

int	ft_printf_str(char *str)
{
	int	len;

	if (str == 0)
	{
		len = ft_putstr_fd("(null)", 1);
		return (len);
	}
	len = ft_putstr_fd(str, 1);
	return (len);
}

int	ft_printf_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	check_type(const char c, va_list *list)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(*list, char)));
	else if (c == 's')
		return (ft_printf_str(va_arg(*list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(*list, int)));
	else if (c == 'u')
		return (ft_printf_unsigned(va_arg(*list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(*list, unsigned int), c));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(*list, unsigned long long)));
	else if (c == '%')
		return (ft_printf_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	int			idx;
	va_list		list;

	va_start(list, format);
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			len += check_type(format[idx + 1], &list);
			idx++;
		}
		else
			len += ft_printf_char(format[idx]);
		idx++;
	}
	va_end(list);
	return (len);
}
