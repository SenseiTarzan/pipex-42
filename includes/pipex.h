/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:03:59 by gcaptari          #+#    #+#             */
/*   Updated: 2024/01/19 11:58:12 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**args;
	char			*name;
	int				std_in;
	int				std_out;
	pid_t			fork_pid;
}				t_cmd;

typedef struct s_pipex
{
	t_cmd		*cmd;
	char		**env;
	char		**path;
}				t_pipex;

void			**array_cpy(void **src);
size_t			count_array(void **array);
unsigned char	free_array(void **array);
unsigned char	ft_free_multi_t_cmd(t_cmd *cmd);
void 			ft_pipex(t_pipex *pipex, int std_in, int std_out);
void			create_pipe(t_cmd *cmd);
char 			**get_path(char **env);
t_cmd			*parse_cmd(char **cmd, char **path);

#endif