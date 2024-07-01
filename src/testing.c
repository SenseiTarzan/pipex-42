/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:56:24 by gcaptari          #+#    #+#             */
/*   Updated: 2024/07/01 13:28:45 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argv(int argc)
{
	if (argc < 5)
	{
		ft_fprintf(2, "pipex: %s\n", "numders args < 5");
		exit(EXIT_FAILURE);
	}
}

void	test_error(int std_err, t_pipex *pipex)
{
	if (std_err != 0)
	{
		pipex->std_out != -1 && close(pipex->std_out);
		pipex->std_in != -1 && close(pipex->std_in);
		exit(EXIT_FAILURE);
	}
}

void	test_cmd(t_pipex *pipex, t_cmd *cmd)
{
	if (!cmd)
	{
		free_array((void **)pipex->path);
		pipex->std_out != -1 && close(pipex->std_out);
		pipex->std_in != -1 && close(pipex->std_in);
		exit(0);
	}
}
