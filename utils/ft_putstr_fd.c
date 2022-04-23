/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:32:57 by donchoi           #+#    #+#             */
/*   Updated: 2021/12/22 12:32:57 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!(s) || fd < 0)
		return (-1);
	len = write(fd, s, ft_strlen(s));
	return (len);
}
