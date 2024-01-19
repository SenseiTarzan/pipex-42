/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:28:00 by gcaptari          #+#    #+#             */
/*   Updated: 2023/12/19 09:36:46 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ALL_BASE_NUMBER_LOWER "0123456789abcdef"
# define ALL_BASE_NUMBER_UPPER "0123456789ABCDEF"

size_t			ft_llutohex_size(unsigned long long n, unsigned char type);
char			*ft_lutohex(unsigned long long n, unsigned char type);
char			*ft_utoa(unsigned int n);
unsigned int	ft_unintlen(unsigned int n);
size_t			ft_putchar(int c);
size_t			ft_putstr(char *str);
size_t			ft_putnbr(int n);
size_t			ft_putnbr_u(unsigned int n);
size_t			ft_puthex(unsigned long long n, unsigned char type);
size_t			ft_putpointer(void *p);
int				ft_printf(const char *format, ...);

#endif
