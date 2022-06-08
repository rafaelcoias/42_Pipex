/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:12 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/24 17:02:40 by rade-sar         ###   ########.fr       */
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
}

static char	*get_cmd_path(t_data *data, char *cmd, char **envp)
{
	char	*add_slash;
	char	*path;
	int		i;

	data->paths = get_env_path(envp);
	if (ft_strchr(cmd, '/') && !access(cmd, F_OK))
		return (cmd);
	else if (ft_strchr(cmd, '/') && access(cmd, F_OK))
		error_msg(CMD_ERROR);
	i = -1;
	while (data->paths[++i])
	{
		add_slash = ft_strjoin(data->paths[i], "/");
		path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	error_msg(CMD_ERROR);
}

void	check_all(t_data *data, int argc, char **argv, char **envp)
{
	int	fd;
	int	fd2;

	(void)argc;
	fd = open(argv[1], O_DIRECTORY);
	fd2 = open(argv[4], O_DIRECTORY);
	if (fd > 0 || fd2 > 0)
		error_msg(DIR_ERROR);
	if (access(argv[1], F_OK))
		error_msg(FILE_ERROR);
	data->path_cmd1 = get_cmd_path(data, data->path_cmd1, envp);
	data->path_cmd2 = get_cmd_path(data, data->path_cmd2, envp);
	if (access(data->path_cmd1, F_OK) || access(data->path_cmd2, F_OK))
		error_msg(CMD_ERROR);
}
