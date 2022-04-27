/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:14:57 by donchoi           #+#    #+#             */
/*   Updated: 2022/04/27 15:10:21 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_calculate(long long tmp, char *base, int baselen, int *len)
{
	if (tmp <= 0)
		return ;
	ft_calculate(tmp / baselen, base, baselen, len);
	*len += write(1, &base[tmp % baselen], 1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int			len;
	long long	baselen;
	long long	tmp;

	len = 0;
	tmp = nbr;
	baselen = ft_strlen(base);
	if (tmp >= 0)
	{
		ft_calculate(tmp / baselen, base, baselen, &len);
		len += write(1, &base[nbr % baselen], 1);
	}
	else
	{
		len += write(1, "-", 1);
		ft_calculate(-nbr / baselen, base, baselen, &len);
		len += write(1, &base[-nbr % baselen], 1);
	}
	return (len);
}
