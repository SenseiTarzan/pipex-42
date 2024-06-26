/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:43:34 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const unsigned char	h = (const unsigned char) c;
	char				*last_char;

	last_char = (char *) NULL;
	while (*str)
	{
		if (*(unsigned char *)str == h)
			last_char = (char *) str;
		str++;
	}
	if (*(unsigned char *)str == h)
		last_char = (char *) str;
	return (last_char);
}
