/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:37:51 by gcaptari          #+#    #+#             */
/*   Updated: 2023/11/24 10:30:13 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	is_set_char(const char *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_strtrim_length(const char *str, size_t len,
	const char *set, int c)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)str;
	i = 0;
	if (c == 0)
		while (*tmp && is_set_char(set, *tmp++))
			i++;
	else if (c == 1)
	{
		tmp += len - 1;
		while (*tmp && is_set_char(set, *tmp--))
			i++;
	}
	return (i);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char					*new_str;
	size_t					len;
	struct s_bypass_trim	trim;

	if (!str || !set)
		return (NULL);
	len = ft_strlen(str);
	trim.len_start = ft_strtrim_length(str, len, set, 0);
	if (trim.len_start == len)
		return (ft_calloc(1, sizeof(char)));
	trim.len_end = ft_strtrim_length(str, len, set, 1);
	trim.real_len = (len - (trim.len_start + trim.len_end));
	new_str = ft_calloc(trim.real_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, (char *)str + trim.len_start, trim.real_len);
	return (new_str);
}
