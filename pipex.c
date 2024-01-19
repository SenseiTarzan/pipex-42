/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:39:24 by gcaptari          #+#    #+#             */
/*   Updated: 2024/01/19 12:00:25 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	exec_cmd(t_cmd *cmd, char **env, int *std_in, int std_out)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (!pid)
	{
		close(cmd->std_in);
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
		dup2(*std_in, STDIN_FILENO);
		close(*std_in);
		if (execve(cmd->name, cmd->args, env) == -1)
		{
			perror("execv");
			exit(EXIT_FAILURE);
		}
		exit(0);
	}else{
		close(*std_in);
		close(std_out);
		close(cmd->std_out);
		*std_in = cmd->std_in;
	}
	return (pid);
}

pid_t	exec_cmd_last(t_cmd *cmd, char **env, int *std_in, int std_out)
{
	pid_t	pid;

	(void)std_in;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (!pid)
	{
		close(cmd->std_out);
		dup2(std_out, STDOUT_FILENO);
		close(std_out);
		dup2(*std_in, STDIN_FILENO);
		close(*std_in);
		if (execve(cmd->name, cmd->args, env) == -1)
		{
			perror("execv");
			exit(EXIT_FAILURE);
		}
		close(cmd->std_in);
		exit(0);
	}else{
		close(cmd->std_out);
		close(cmd->std_in);
		close(*std_in);
		close(std_out);
	}
	return (pid);
}

void	ft_fork_wait(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		waitpid(tmp->fork_pid, NULL, 0);
		tmp = tmp->next;
	}
}

void 	ft_pipex(t_pipex *pipex, int std_in, int std_out)
{
	t_cmd	*cmd;
	int		std_new;

	cmd = pipex->cmd;
	std_new = std_in;
	while (cmd)
	{
		create_pipe(cmd);
		if (cmd->next == NULL)
			cmd->fork_pid = exec_cmd_last(cmd, pipex->env, &std_new, std_out);
		else 
			cmd->fork_pid = exec_cmd(cmd, pipex->env, &std_new, cmd->std_out);
		cmd = cmd->next;
	}
	ft_fork_wait(pipex->cmd);
	ft_free_multi_t_cmd(pipex->cmd);
}




int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	t_cmd	*cmd_parsed;
	int     std_in;
	int     std_out;

	std_in = open(argv[1], O_RDONLY);
	std_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	argv[argc - 1] = NULL;
	if (std_in == -1 || std_out == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	pipex.path = get_path(env);
	cmd_parsed = parse_cmd(&argv[2], pipex.path);
	pipex.cmd = cmd_parsed;
	pipex.env = env;
	ft_pipex(&pipex, std_in, std_out);
	free_array((void **)pipex.path);
	return (0);
}
