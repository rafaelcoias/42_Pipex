/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:06 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/24 17:03:05 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_all(t_data data)
{
	int	i;

	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	free(data.path_cmd1);
	free(data.path_cmd2);
	i = 0;
	while (data.paths[i])
		free(data.paths[i++]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		error_msg(ARG_ERROR);
	check_all(&data, argc, argv, envp);
	data.fd_in = open(argv[1], O_RDONLY);
	data.fd_out = open(argv[4], O_WRONLY | O_CREAT | 0744);
	data.envp = envp;
	ft_strcpy(data.cmd1, argv[2]);
	ft_strcpy(data.cmd2, argv[3]);
	if (pipe(data.fd_pipe) == -1)
		error_msg(PIPE_ERROR);
	dup2(data.fd_in, STDIN_FILENO);
	process_pipe(&data);
	free_all(data);
	return (0);
}
