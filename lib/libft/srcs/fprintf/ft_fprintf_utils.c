/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:41 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:38 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprintstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	else
		ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ft_fprintnbr(int fd, int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_fprintstr(fd, num);
	free(num);
	return (len);
}

int	ft_fprintpourcent(int fd)
{
	return (write(fd, "%", 1));
}
