/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:37:42 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t		size;
	char		*new_str;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (start >= size || len == 0)
		return (ft_calloc(1, sizeof (char)));
	if ((size - start) < len)
		len = size - start;
	new_str = (char *) ft_calloc(len + 1, sizeof (char));
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, ((char *)str) + start, len);
	return (new_str);
}
