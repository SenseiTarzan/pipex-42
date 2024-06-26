/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:42:09 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 12:46:44 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	**array_cpy(void **src)
{
	void	**dst;
	void	**tmp;
	void	**move;

	if (!src)
		return (NULL);
	tmp = src;
	while (*tmp != NULL)
		tmp++;
	dst = ft_calloc(((tmp - src) + 1), sizeof(char *));
	if (!dst)
		return (NULL);
	tmp = dst;
	move = src;
	while (*move != NULL)
		*tmp++ = ft_strdup(*move++);
	return (dst);
}

size_t	count_array(void **array)
{
	void	**tmp;

	tmp = array;
	while (*tmp)
		tmp++;
	return (tmp - array);
}

unsigned char	free_array(void **array)
{
	void	**tmp;

	if (!array)
		return (0);
	tmp = array;
	while (*tmp != NULL)
		free(*tmp++);
	free(array);
	return (0);
}
