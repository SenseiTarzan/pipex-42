/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:56:24 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 13:12:01 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
