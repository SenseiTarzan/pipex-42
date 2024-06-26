/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:02:44 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	const size_t	len = ft_strlen(src);
	void			*new_str;
	int				*crasher;

	crasher = NULL;
	if (!src)
	{
		*crasher = 42;
		return (NULL);
	}
	new_str = ft_calloc(len + 1, sizeof (char));
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, src, len);
	return ((char *) new_str);
}
