/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:01:31 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_intlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n == 2147483647)
		return (10);
	else if (n < 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static long	ft_abs(int n)
{
	if (n < 0)
		return (-(long)n);
	return ((long) n);
}

char	*ft_itoa(int n)
{
	long			bypass_limit;
	unsigned int	what;
	unsigned int	len;
	char			*new_str;

	len = ft_intlen(n);
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	what = 0;
	bypass_limit = ft_abs(n);
	if (n < 0)
	{
		*new_str = '-';
		what = 1;
	}
	while (len-- > what)
	{
		*(new_str + len) = bypass_limit % 10 + '0';
		bypass_limit /= 10;
	}
	return (new_str);
}
