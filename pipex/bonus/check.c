/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:12 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/16 00:35:50 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_all(t_data *data, int argc, char **argv, char **envp)
{
	int	fd;
	int	fd2;

	(void)argc;
	(void)envp;
	(void)data;
	fd = open(argv[1], O_DIRECTORY);
	fd2 = open(argv[4], O_DIRECTORY);
	if (fd > 0 || fd2 > 0)
		error_msg(DIR_ERROR);
	if (access(argv[1], F_OK))
		error_msg(FILE_ERROR);
}
