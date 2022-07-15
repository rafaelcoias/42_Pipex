/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:35 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/16 00:29:57 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

/* DEFINE ERRORS */

# define ARG_ERROR "Wrong number of arguments.\n"
# define FILE_ERROR "Could not access file (file path may not exist).\n"
# define DIR_ERROR "Argument is a directory, it must be a file.\n"
# define PIPE_ERROR "Pipe function error.\n"
# define FORK_ERROR "Fork function error.\n"
# define EXEC_ERROR "Exec function error."
# define CMD_ERROR "Argument is not a valid shell command.\n"

/* STRUCT */

typedef struct s_data
{
	int	fd_in;
	int	fd_out;
	int	fd_pipe[2];
	int	here_doc;
	int	argc;
	char	**argv;
	char	**envp;
	char	**cmd1;
	char	*path_cmd1;
	char	**cmd2;
	char	*path_cmd2;
	char	**paths;
}		t_data;


/* CHECK FUNCTIONS */

void	check_all(t_data *data, int argc, char **argv, char **envp);
void	error_msg(char *str);

/* PROCESS PIPE FUNCTIONS */

void	process_pipe(t_data *data);

char	*get_path(t_data *data, int arg);

#endif
