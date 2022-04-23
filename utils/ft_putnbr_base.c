/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:14:57 by donchoi           #+#    #+#             */
/*   Updated: 2022/04/23 16:14:57 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_calculate(long long nbr, char *base, int baselen, int *len)
{
	if (nbr == 0)
		return ;
	ft_calculate(nbr / baselen, base, baselen, len);
	*len += ft_putstr_fd(&base[nbr % baselen], 1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int			len;
	int			baselen;
	long long	tmp;

	len = 0;
	tmp = nbr;
	baselen = ft_strlen(base);
	if (tmp >= 0)
	{
		ft_calculate(tmp / baselen, base, baselen, &len);
		len += ft_putstr_fd(&base[tmp % baselen], 1);
	}
	else
	{
		write(1, "-", 1);
		ft_calculate(-tmp / baselen, base, baselen, &len);
		len += ft_putstr_fd(&base[-tmp % baselen], 1);
	}
	return (len);
}
