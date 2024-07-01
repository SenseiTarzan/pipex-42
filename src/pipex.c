/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:39:24 by gcaptari          #+#    #+#             */
/*   Updated: 2024/07/01 13:28:55 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	exec_cmd(t_pipex *pipex, t_cmd *cmd, int *std_in)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}
	if (!pid)
		exec_cmd_pipe(pipex, cmd, std_in);
	if (*std_in != -1)
		close(*std_in);
	close(cmd->std_out);
	*std_in = cmd->std_in;
	return (pid);
}

pid_t	exec_cmd_last(t_pipex *pipex, t_cmd *cmd, int *std_in, int std_out)
{
	pid_t	pid;

	(void)std_in;
	pid = fork();
	if (pid < 0)
	{
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}
	if (!pid)
		exec_last_cmd_pipe(pipex, cmd, std_in, std_out);
	*std_in != -1 && close(*std_in);
	std_out != -1 && close(std_out);
	return (pid);
}

void	ft_fork_wait(t_cmd *cmd, int *status)
{
	int	state;

	while (cmd && waitpid(cmd->fork_pid, &state, 0) >= 0)
	{
		if (WIFEXITED(state))
			cmd = cmd->next;
	}
	*status = WIFEXITED(state);
}

int	ft_pipex(t_pipex *pipex, int std_in, int std_out)
{
	t_cmd	*cmd;
	int		std_new;
	int		status;

	cmd = pipex->cmd;
	std_new = std_in;
	while (cmd)
	{
		if (cmd->next == NULL)
			cmd->fork_pid = exec_cmd_last(pipex, cmd, &std_new, std_out);
		else
		{
			create_pipe(cmd);
			cmd->fork_pid = exec_cmd(pipex, cmd, &std_new);
		}
		cmd = cmd->next;
	}
	ft_fork_wait(pipex->cmd, &status);
	ft_free_multi_t_cmd(pipex->cmd);
	free_array((void **)pipex->path);
	return (status);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	t_cmd	*cmd_parsed;
	int		std_err;

	if (!env)
	{
		ft_fprintf(2, "pipex: %s\n", "Env is NULL");
		return (0);
	}
	check_argv(argc);
	std_err = 0;
	pipex.std_in = open(argv[1], O_RDONLY);
	if (pipex.std_in == -1)
		ft_fprintf(2, "pipex: %s : %s\n", argv[1], strerror(errno));
	pipex.std_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.std_out == -1 && ++std_err)
		ft_fprintf(2, "pipex: %s : %s\n", argv[argc - 1], strerror(errno));
	argv[argc - 1] = NULL;
	test_error(std_err, &pipex);
	pipex.path = get_path(env);
	cmd_parsed = parse_cmd(&argv[2], pipex.path);
	test_cmd(&pipex, cmd_parsed);
	pipex.cmd = cmd_parsed;
	pipex.env = env;
	return (ft_pipex(&pipex, pipex.std_in, pipex.std_out));
}
