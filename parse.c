/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:06:09 by gcaptari          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:25 by gcaptari         ###   ########.fr       */
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


t_cmd *ft_cmd_new(char *name, char **args)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->name = name;
	new->args = (char **)array_cpy((void **)args);
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

char **get_path(char **env)
{
	char	**tmp;

	tmp = env;
	while (*tmp)
	{
		if (ft_strncmp(*tmp, "PATH=", 5) == 0)
			return (ft_split(*tmp + 5, ':'));
		tmp++;
	}
	return (NULL);
}

static char *get_real_command(char *name, char **path)
{
	char	*cmd_path;
	char	*cmd_file;
	char	**tmp;

	tmp = path;
	while (*tmp)
	{
		cmd_path = ft_strjoin(*tmp, "/");
		cmd_file = ft_strjoin(cmd_path, name);
		free(cmd_path);
		if (access(cmd_file, F_OK|X_OK) == 0)
			return (cmd_file);
		free(cmd_file);
		tmp++;
	}
	return (ft_strdup(name));
}

t_cmd	*parse_cmd(char **cmd, char **path)
{
	t_cmd	*cmd_parsed;
	t_cmd	*tmp;
	char	**split;
	char	**move;
	move = cmd;
	if (!move)
		return (NULL);
	cmd_parsed = NULL;
	while (*move)
	{
		split = ft_split(*move++, ' ');
		if (!split && !ft_free_multi_t_cmd(cmd_parsed))
			return (NULL);
		tmp = ft_cmd_new(get_real_command(split[0], path), split);
		free_array((void **)split);
		if (!tmp && !ft_free_multi_t_cmd(cmd_parsed))
			return (NULL);
		ft_cmd_add_back(&cmd_parsed, tmp);
	}
	return (cmd_parsed);
}
