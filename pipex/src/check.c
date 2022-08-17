/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:35:12 by rade-sar          #+#    #+#             */
/*   Updated: 2022/08/17 21:09:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_all(t_data *data, char **argv)
{
	int	fd;
	int	fd2;

	fd = open(argv[1], O_DIRECTORY);
	fd2 = open(argv[4], O_DIRECTORY);
	if (fd > 0 || fd2 > 0)
		error_msg(data, DIR_ERROR);
	if (access(argv[1], F_OK))
		error_msg(data, FILE_ERROR);
	close(fd);
	close(fd2);
}
