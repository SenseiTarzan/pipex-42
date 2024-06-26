/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:43:48 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 12:43:56 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

unsigned char	ft_free_multi_t_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*tmp_cmd;

	if (!cmd)
		return (0);
	tmp = cmd;
	while (tmp != NULL)
	{
		free_array((void **)tmp->args);
		free(tmp->name);
		tmp_cmd = tmp;
		tmp = tmp->next;
		free(tmp_cmd);
	}
	return (0);
}

t_cmd	*ft_cmd_new(char *name, char **args)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->name = name;
	new->args = (char **)array_cpy((void **)args);
	if (!new->args)
		return (free(new->name), free(new), NULL);
	new->next = NULL;
	return (new);
}

void	ft_cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!*cmd)
	{
		*cmd = new;
		return ;
	}
	last = *cmd;
	while (last->next)
		last = last->next;
	last->next = new;
}
