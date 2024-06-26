/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:40:02 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 14:27:02 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execution_command(t_pipex *pipex, t_cmd *cmd, char **env)
{
	if ((ft_strncmp(cmd->name, "./", 2) == 0 || ft_strncmp(cmd->name, "/",
				1) == 0) && access(cmd->name, F_OK) != 0)
	{
		ft_free_multi_t_cmd(pipex->cmd);
		free_array((void **)pipex->path);
		exit(ENOENT);
	}
	if (execve(cmd->name, cmd->args, env) == -1)
	{
		ft_free_multi_t_cmd(pipex->cmd);
		free_array((void **)pipex->path);
		exit(253);
	}
	ft_free_multi_t_cmd(pipex->cmd);
	free_array((void **)pipex->path);
}

void	exec_cmd_pipe(t_pipex *pipex, t_cmd *cmd, int *std_in)
{
	close(pipex->std_out);
	close(cmd->std_in);
	dup2(cmd->std_out, STDOUT_FILENO);
	close(cmd->std_out);
	if (*std_in != -1)
	{
		dup2(*std_in, STDIN_FILENO);
		close(*std_in);
		execution_command(pipex, cmd, pipex->env);
	}
	else
	{
		ft_free_multi_t_cmd(pipex->cmd);
		free_array((void **)pipex->path);
	}
	exit(EXIT_SUCCESS);
}

void	exec_last_cmd_pipe(t_pipex *pipex, t_cmd *cmd, int *std_in,
		int std_out)
{
	if (std_out != -1)
	{
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
	}
	if (*std_in != -1)
	{
		dup2(*std_in, STDIN_FILENO);
		close(*std_in);
	}
	execution_command(pipex, cmd, pipex->env);
	exit(EXIT_SUCCESS);
}
