/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:24:28 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/27 22:35:23 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


static void	process_child(t_data *data, int arg)
{
	char	*path;
	
	path = get_path(data, arg);
	close(data->fd_pipe[0]);
	if (arg != data->argc - 2)
		dup2(data->fd_pipe[1], STDOUT_FILENO);
	else
		dup2(data->fd_out, STDOUT_FILENO);
	if (execve(path, ft_split(data->argv[arg], ' '), data->envp) == -1)
		error_msg(data, EXEC_ERROR);
}

void	process_pipe(t_data *data)
{
	int	pid_child;
	int	i;

	i = 1;
	dup2(data->fd_in, STDIN_FILENO);
	while (++i != data->argc - 1)
	{
		if (pipe(data->fd_pipe) == -1)
			error_msg(data, PIPE_ERROR);
		pid_child = fork();
		if (pid_child == -1)
			error_msg(data, FORK_ERROR);
		if (!pid_child)
			process_child(data, i);
		close(data->fd_pipe[1]);
		waitpid(pid_child, 0, 0);
		dup2(data->fd_pipe[0], STDIN_FILENO);	
	}
}
