/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:06:09 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 12:44:41 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	**tmp;

	tmp = env;
	if (count_array((void **)env) == 0)
		return (NULL);
	while (*tmp)
	{
		if (ft_strncmp(*tmp, "PATH=", 5) == 0)
			return (ft_split(*tmp + 5, ':'));
		tmp++;
	}
	return (NULL);
}

static char	*get_real_command(char *name, char **path)
{
	char	*cmd_path;
	char	*cmd_file;
	char	**tmp;

	if (!name)
		return (ft_strdup(""));
	if (ft_strlen(name) >= 2 && ft_strncmp(name, "./", 2) == 0)
		return (ft_strdup(name));
	if (ft_strlen(name) >= 2 && ft_strncmp(name, "/", 1) == 0)
		return (ft_strdup(name));
	if (!path || !*path)
		return (ft_strdup(name));
	tmp = path;
	while (tmp && *tmp)
	{
		cmd_path = ft_strjoin(*tmp, "/");
		cmd_file = ft_strjoin(cmd_path, name);
		free(cmd_path);
		if (access(cmd_file, F_OK | X_OK) == 0)
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
		split = ft_split(*move, ' ');
		if (!split && !ft_free_multi_t_cmd(cmd_parsed))
			return (NULL);
		tmp = ft_cmd_new(get_real_command(split[0], path), split);
		free_array((void **)split);
		if (!tmp && !ft_free_multi_t_cmd(cmd_parsed))
			return (NULL);
		ft_cmd_add_back(&cmd_parsed, tmp);
		++move;
	}
	return (cmd_parsed);
}
