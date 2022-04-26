/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:09:58 by donchoi           #+#    #+#             */
/*   Updated: 2022/04/26 20:43:37 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int nbr)
{
	size_t	len;

	len = ft_putnbr_base(nbr, "0123456789");
	return (len);
}

int	ft_printf_hex(unsigned int nbr, const char type)
{
	size_t	len;

	len = 0;
	if (type == 'X')
		len = ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		len = ft_putnbr_base(nbr, "0123456789abcdef");
	return (len);
}

static void	ft_putptr(unsigned long long ptr, size_t *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += ft_putchar_fd('0' + ptr, 1);
		else
			*len += ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	len += ft_putstr_fd("0x", 1);
	ft_putptr(ptr, &len);
	return (len);
}
