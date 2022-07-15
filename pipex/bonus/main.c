/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:06 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/16 00:21:55 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (envp[i])
		return (ft_split(&envp[i][5], ':'));
	return (NULL);
}

static void	free_all(t_data *data)
{
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	ft_free_mtx(data->cmd1);
	ft_free_mtx(data->cmd2);
	free(data->path_cmd1);
	free(data->path_cmd2);
	ft_free_mtx(data->paths);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		error_msg(ARG_ERROR);
	check_all(&data, argc, argv, envp);
	data.fd_in = open(argv[1], O_RDONLY);
	data.fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | 0666);
	data.envp = envp;
	data.argc = argc;
	data.argv = argv;
	data.paths = get_env_path(envp);
	if (pipe(data.fd_pipe) == -1)
		error_msg(PIPE_ERROR);
	process_pipe(&data);
	free_all(&data);
}
