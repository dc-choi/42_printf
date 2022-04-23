/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:31:31 by donchoi           #+#    #+#             */
/*   Updated: 2021/12/22 12:31:31 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	len;

	if (fd < 0)
		return (-1);
	len = write(fd, &c, 1);
	return (len);
}
