/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <lsherry@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:03:04 by lsherry           #+#    #+#             */
/*   Updated: 2021/12/02 00:03:06 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putptr(void *p);
int		ft_puthexnbr(int nbr, char x);
int		ft_putstring(char *s, int fd);
int		ft_putnumber(long int n, int fd);
int		ft_putchar(char c);
char	ft_hex_digit(int v, char x);

#endif
