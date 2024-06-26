/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:03:59 by gcaptari          #+#    #+#             */
/*   Updated: 2024/06/26 13:25:07 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**args;
	char			*name;
	int				std_in;
	int				std_out;
	pid_t			fork_pid;
}					t_cmd;

typedef struct s_pipex
{
	t_cmd			*cmd;
	char			**env;
	char			**path;
	int				std_in;
	int				std_out;
}					t_pipex;

void				**array_cpy(void **src);
size_t				count_array(void **array);
unsigned char		free_array(void **array);
unsigned char		ft_free_multi_t_cmd(t_cmd *cmd);
t_cmd				*ft_cmd_new(char *name, char **args);
void				ft_cmd_add_back(t_cmd **cmd, t_cmd *new);
void				create_pipe(t_cmd *cmd);
char				**get_path(char **env);
t_cmd				*parse_cmd(char **cmd, char **path);

void	test_error(int std_err, t_pipex *pipex);
void				test_cmd(t_pipex *pipex, t_cmd *cmd);
void				exec_cmd_pipe(t_pipex *pipex, t_cmd *cmd, int *std_in);
void				exec_last_cmd_pipe(t_pipex *pipex, t_cmd *cmd, int *std_in,
						int std_out);
int					ft_pipex(t_pipex *pipex, int std_in, int std_out);

#endif
