/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:24:28 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/16 00:37:40 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	process_father(t_data *data)
{
	close(data->fd_pipe[1]);
	dup2(data->fd_pipe[0], STDIN_FILENO);	
}

static void	process_first_pipe(t_data *data)
{
	char	*path;
	
	path = get_path(data, 2);
	close(data->fd_pipe[0]);
	dup2(data->fd_pipe[1], STDOUT_FILENO);
	if (execve(path, ft_split(data->argv[2], ' '), data->envp) == -1)
		error_msg(EXEC_ERROR);
}

static void	process_middle_pipes(t_data *data)
{
	char	*path;
	int	pid;
	int	i;

	i = 2;
	while (++i != data->argc -2)
	{
		pid = fork();
		if (pid == -1)
			error_msg(FORK_ERROR);
		else if (!pid)
		{
			path = get_path(data, i);
			close(data->fd_pipe[0]);
			dup2(data->fd_pipe[1], STDOUT_FILENO);
			if (execve(path, ft_split(data->argv[i], ' '), data->envp) == -1)
				error_msg(EXEC_ERROR);
		}
		process_father(data);
		waitpid(pid, 0, 0);
	}
}

static void	process_last_pipe(t_data *data, int arg)
{
	char	*path;

	path = get_path(data, data->argc - 2);
	close(data->fd_pipe[0]);
	dup2(data->fd_out, STDOUT_FILENO);
	if (execve(path, ft_split(data->argv[arg], ' '), data->envp) == -1)
		error_msg(EXEC_ERROR);
}

void	process_pipe(t_data *data)
{
	int	pid_child;
	int	pid_child2;

	dup2(data->fd_in, STDIN_FILENO);
	pid_child = fork();
	if (pid_child == -1)
		error_msg(FORK_ERROR);
	if (!pid_child)
		process_first_pipe(data);
	process_father(data);
	waitpid(pid_child, 0, 0);
	process_middle_pipes(data);
	pid_child2 = fork();
	if (pid_child2 == -1)
		error_msg(FORK_ERROR);
	if (!pid_child2)
		process_last_pipe(data, data->argc - 2);
	waitpid(pid_child2, 0, 0);
}
