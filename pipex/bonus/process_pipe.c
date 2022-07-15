/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:24:28 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/15 14:18:30 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	process_child(t_data *data)
{
	close(data->fd_pipe[0]);
	dup2(data->fd_pipe[1], STDOUT_FILENO);
	if (execve(data->path_cmd1, data->cmd1, data->envp) == -1)
		error_msg(EXEC_ERROR);
}

static void	process_father(t_data *data)
{
	close(data->fd_pipe[1]);
	dup2(data->fd_pipe[0], STDIN_FILENO);	
}

void	process_pipe(t_data *data)
{
	int	pid_child;
	int	pid_child2;

	pid_child = fork();
	if (pid_child == -1)
		error_msg(FORK_ERROR);
	if (!pid_child)
		process_child(data);
	process_father(data);
	waitpid(pid_child, 0, 0);	
	pid_child2 = fork();
	if (!pid_child2)
		if (execve(data->path_cmd2, data->cmd2, data->envp) == -1)
			error_msg(EXEC_ERROR);
	waitpid(pid_child2, 0, 0);
}
