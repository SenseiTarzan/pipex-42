/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:34:29 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/22 09:25:46 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	number;
	int				signe;
	char			*tmp;

	if (*str == 0)
		return (0);
	tmp = (char *)str;
	number = 0;
	while ((*tmp >= 9 && *tmp <= 13) || *tmp == 32)
		tmp++;
	signe = 1;
	if (*tmp == 43 || *tmp == 45)
	{
		if (*tmp == 45)
			signe = -signe;
		tmp++;
	}
	while (*tmp && ft_isdigit(*tmp))
	{
		number = number * 10 +(*tmp++) - 48;
	}
	return (signe * number);
}
