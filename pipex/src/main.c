/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:06 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 13:27:50 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	here_doc(t_data *data, char **argv, int argc)
{
	char	*limiter;
	char	*line;

	if (ft_strcmp(argv[1], "here_doc"))
		return (0);
	if (argc < 6)
		return (0);
	data->fd_heredoc = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_heredoc == -1)
		error_msg(data, OPEN_ERROR);
	limiter = ft_strjoin(argv[2], "\n");
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		if (!ft_strcmp(line, limiter))
			break ;
		write(data->fd_heredoc, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
	close(data->fd_heredoc);
	data->fd_in = open(".here_doc", O_RDONLY);
	return (1);
}

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
	close(data->fd_in);
	close(data->fd_out);
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	unlink(".here_doc");
	ft_free_mtx(data->paths);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		error_msg(&data, ARG_ERROR);
	data.here_doc = here_doc(&data, argv, argc);
	if (!data.here_doc)
	{
		data.here_doc = 0;
		check_all(&data, argv);
		data.fd_in = open(argv[1], O_RDONLY);
	}
	if (!data.here_doc)
		data.fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		data.fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (data.fd_out == -1 || data.fd_in == -1)
		error_msg(&data, OPEN_ERROR);
	data.envp = envp;
	data.argc = argc;
	data.argv = argv;
	data.paths = get_env_path(envp);
	process_pipe(&data);
	free_all(&data);
}
