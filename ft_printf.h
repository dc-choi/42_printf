/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:52:23 by donchoi           #+#    #+#             */
/*   Updated: 2022/04/22 17:23:03 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		check_type(const char c, va_list *ap);

int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(int nbr);
int		ft_printf_hex(unsigned int nbr, const char type);
int		ft_printf_ptr(unsigned long long ptr);

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_base(long long nbr, char *base);

#endif