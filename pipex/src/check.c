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

void	check_all(int argc, char **argv)
{
	int	fd;
	int	fd2;

	(void)argc;
	fd = open(argv[1], O_DIRECTORY);
	fd2 = open(argv[4], O_DIRECTORY);
	if (fd > 0 || fd2 > 0)
		error_msg(DIR_ERROR);
	if (access(argv[1], F_OK) == -1 || access(argv[4], F_OK) == -1)
		error_msg(FILE_ERROR);
}
