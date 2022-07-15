/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:08:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/16 00:30:30 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(t_data *data, int arg)
{	
	char	*add_slash;
	char	*path;
	char	*cmd;
	int	i;
	
	cmd = data->argv[arg];
	if (ft_strchr(cmd, '/') && !access(cmd, F_OK))
		return (cmd);
	else if (ft_strchr(cmd, '/') && access(cmd, F_OK))
		error_msg(CMD_ERROR);
	i = -1;
	while (data->paths[++i])
	{
		add_slash = ft_strjoin(data->paths[i], "/");
		path = ft_strjoin(add_slash, data->cmd1[0]);
		free(add_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	error_msg(CMD_ERROR);
	return (NULL);
}
