/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:14:51 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*tmp = str;

	while (*tmp)
	{
		if (tmp[0] == '\0')
			return (tmp - str);
		if (tmp[1] == '\0')
			return (tmp - str + 1);
		if (tmp[2] == '\0')
			return (tmp - str + 2);
		if (tmp[3] == '\0')
			return (tmp - str + 3);
		if (tmp[4] == '\0')
			return (tmp - str + 4);
		if (tmp[5] == '\0')
			return (tmp - str + 5);
		if (tmp[6] == '\0')
			return (tmp - str + 6);
		if (tmp[7] == '\0')
			return (tmp - str + 7);
		tmp += 8;
	}
	return (tmp - str);
}
