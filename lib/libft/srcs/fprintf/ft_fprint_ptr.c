/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:01 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:38 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	ft_fput_ptr(int fd, uintptr_t num)
{
	if (num >= 16)
	{
		ft_fput_ptr(fd, num / 16);
		ft_fput_ptr(fd, num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), fd);
		else
			ft_putchar_fd((num - 10 + 'a'), fd);
	}
}

int	ft_fprint_ptr(int fd, void *ptr)
{
	int					print_length;
	unsigned long long	mem;

	if (ptr == NULL)
		return (ft_printstr("(nil)"));
	mem = (unsigned long long)ptr;
	print_length = 0;
	print_length += write(1, "0x", 2);
	if (mem == 0)
		print_length = write(1, "0", 1);
	else
	{
		ft_fput_ptr(fd, mem);
		print_length = ft_ptr_len(mem);
	}
	return (print_length);
}
