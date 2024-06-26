/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:25:33 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 15:26:41 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fprintchar(int fd, char c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

static int	ft_formats(int fd, va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_fprintchar(fd, va_arg(args, int));
	else if (format == 's')
		print_length += ft_fprintstr(fd, va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_fprint_ptr(fd, va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_fprintnbr(fd, va_arg(args, int));
	else if (format == 'u')
		print_length += ft_fprint_unsigned(fd, va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_fprint_hex(fd, va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_fprintpourcent(fd);
	return (print_length);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_formats(fd, args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_fprintchar(fd, format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
