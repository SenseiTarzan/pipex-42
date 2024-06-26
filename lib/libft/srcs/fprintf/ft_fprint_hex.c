/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:02 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:38 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int num)
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

static void	ft_fput_hex(int fd, unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_fput_hex(fd, num / 16, format);
		ft_fput_hex(fd, num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), fd);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), fd);
		}
	}
}

int	ft_fprint_hex(int fd, unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", fd));
	else
		ft_fput_hex(fd, num, format);
	return (ft_hex_len(num));
}
