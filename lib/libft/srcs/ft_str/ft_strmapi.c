/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:53:50 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/21 12:15:54 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char	*new_str;
	char	*tmp;
	char	*origin;
	size_t	i;

	if (!str || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	tmp = new_str;
	i = 0;
	origin = (char *)str;
	while (*origin)
		*tmp++ = f(i++, *origin++);
	*tmp = 0;
	return (new_str);
}
